/*
** EPITECH PROJECT, 2018
** MyIRC - Server
** File description:
** Command PART
*/

/**
*@brief Command PART
*
*@file cmd_part.c
*@author Hugon Bastien
*@date 24-05-2018
*/
#include "server.h"

/**
*@brief Get the message object
*
*@param msg The message to transform
*@return char* The message transformed
*/
static char *get_message(users_t *usr, char **msg)
{
	int len;
	char *buff;

	asprintf(&buff, ":%s PRIVMSG %s :", usr->nick, msg[1]);
	if (!buff)
		exit(84);
	for (int i = 2; msg[i] != NULL; i++) {
		len = strlen(buff) + strlen(msg[i]) + 2;
		buff = realloc(buff, len);
		if (!buff)
			exit(84);
		if (i != 2)
			strcat(buff, " ");
		strcat(buff, msg[i]);
	}
	return (buff);
}

/**
*@brief Just send a 404 to an user
*
*@param usr The user to send the message
*@param chan The channel parameter
*/
static void send_404(users_t *usr, char *chan)
{
	char buff[50] = { 0 };

	sprintf(buff, REPL_404, chan);
	send_message(usr, buff);
}

static void send_privmsg(server_t *srv, users_t *usr, char **cmd)
{
	chan_t *chan;
	users_t *user;
	char buff[50] = { 0 };
	char *msg = get_message(usr, cmd);

	if ((user = user_exists(srv->chan->users, cmd[1])))
		send_message(user, msg);
	else if ((chan = get_channel(srv, cmd[1])))
		if (!is_on_chan(chan, usr->fd))
			send_404(usr, chan->name);
		else
			chan_broadcast_message(chan, msg);
	else {
		sprintf(buff, REPL_401, cmd[1]);
		send_message(usr, buff);
	}
	free(msg);
}

/**
*@brief Broadcast message
*
*@param ptr The server_t struct
*@param usr The user who called this command
*@param cmd The cmd called
*/
void cmd_privmsg(void *ptr, users_t *usr, char **cmd)
{
	server_t *srv = ptr;

	if (!cmd[1] || !cmd[2]) {
		send_message(usr, REPL_412);
		return ;
	}
	send_privmsg(srv, usr, cmd);
}