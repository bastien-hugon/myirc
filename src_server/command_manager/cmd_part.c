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
*@brief Leave a channel and broadcast a leave message
*
*@param chan The chan_t struct to leave
*@param usr The user who wants to quit
*@param chan_name The channel name
*@param l_msg The msg when leave the chan
*/
void leave_channel(server_t *srv, chan_t *chan, users_t *usr, \
char **cmd)
{
	users_t *tmp = chan->users;
	users_t *last = NULL;
	char msg[50] = { 0 };

	if (cmd[2] != NULL)
		sprintf(msg, ":%s PART %s :%s", usr->nick, cmd[1], cmd[2]);
	else
		sprintf(msg, ":%s PART %s", usr->nick, cmd[1]);
	chan_broadcast_message(chan, msg);
	while (tmp) {
		if (usr->fd == tmp->fd) {
			(last) ? (last->next = tmp->next) : \
			(chan->users = tmp->next);
			break;
		}
		last = tmp;
		tmp = tmp->next;
	}
	if (chan->users == NULL)
		remove_channel(srv, chan);
}

/**
*@brief Quit the channel
*
*@param ptr The server_t struct
*@param usr The user who called this command
*@param cmd The cmd called
*/
void cmd_part(void *ptr, users_t *usr, char **cmd)
{
	server_t *srv = ptr;
	char msg[50] = { 0 };
	chan_t *chan;

	if (!cmd[1]) {
		sprintf(msg, REPL_461, "PART");
		send_message(usr, msg);
		return ;
	}
	chan = get_channel(srv, cmd[1]);
	if (!chan) {
		sprintf(msg, REPL_403, cmd[1]);
		send_message(usr, msg);
		return ;
	} else if (!is_on_chan(chan, usr->fd)) {
		sprintf(msg, REPL_442, cmd[1]);
		send_message(usr, msg);
		return ;
	}
	leave_channel(srv, chan, usr, cmd);
}