/*
** EPITECH PROJECT, 2018
** MyIRC - Server
** File description:
** Commande Join
*/

/**
*@brief JOIN command
*
*@file cmd_join.c
*@author Hugon Bastien
*@date 17-05-2018
*/
#include "server.h"

/**
*@brief Count the channels where the user is on
*
*@param srv The main server_t struct
*@param fd The user's fd
*@return unsigned int The channel's number where the user is on
*/
static unsigned int count_user_channels(server_t *srv, int fd)
{
	chan_t *tmp = srv->chan->next;
	unsigned int res = 0;

	while (tmp != NULL) {
		if (is_on_chan(tmp, fd))
			++res;
		tmp = tmp->next;
	}
	return (res);
}

/**
*@brief Put an user to a chan if it exists or create it if it not exists
*
*@param srv The main server_t struct
*@param usr The user to put on a channel
*@param chan_name The channel name
*/
static void put_user_to_chan(server_t *srv, users_t *usr, char *chan_name)
{
	chan_t *chan;
	char buffer[128];

	if (count_user_channels(srv, usr->fd) >= 20) {
		sprintf(buffer, REPL_405, chan_name);
		send_message(usr, buffer);
		return ;
	}
	chan = get_channel(srv, chan_name);
	if (!chan)
		chan = create_and_add_chan(srv, chan_name);
	else if (is_on_chan(chan, usr->fd)) {
		sprintf(buffer, REPL_443, usr->nick, chan_name);
		send_message(usr, buffer);
		return ;
	}
	join_channel(srv, usr->fd, chan_name);
	sprintf(buffer, ":%s JOIN %s", usr->nick, chan_name);
	chan_broadcast_message(chan, buffer);
}

/**
*@brief Join an user to a channel
*
*@param ptr The server_t struct
*@param usr The user who called this command
*@param cmd The cmd called
*/
void cmd_join(void *ptr, users_t *usr, char **cmd)
{
	server_t *srv = ptr;
	char msg[50] = { 0 };

	if (!cmd[1]) {
		sprintf(msg, REPL_461, "JOIN");
		send_message(usr, msg);
	} else if (!is_logged(usr))
		send_message(usr, msg);
	else
		put_user_to_chan(srv, usr, cmd[1]);
}