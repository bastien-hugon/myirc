/*
** EPITECH PROJECT, 2018
** MyIRC - Server
** File description:
** Command QUIT
*/

/**
*@brief Command QUIT
*
*@file cmd_quit.c
*@author Hugon Bastien
*@date 24-05-2018
*/
#include "server.h"

static void remove_user(chan_t *chan, users_t *usr)
{
	users_t *tmp = chan->users;

	if (tmp->fd == usr->fd) {
		chan->users = usr->next;
		free(usr->nick);
		free(usr);
		return ;
	}
	while (tmp->next && tmp->next->fd != usr->fd)
		tmp = tmp->next;
	if (tmp->next != NULL) {
		tmp->next = usr->next;
		free(usr->nick);
		free(usr);
	}
}

/**
*@brief Quit the server
*
*@param ptr The server_t struct
*@param usr The user who called this command
*@param cmd The cmd called
*/
void cmd_quit(void *ptr, users_t *usr, char **cmd)
{
	chan_t *chan = ((server_t *)ptr)->chan->next;
	char *cmds[2] = {0, "quit"};
	(void)cmd;

	while (chan != NULL) {
		if (is_on_chan(chan, usr->fd)) {
			cmds[0] = strdup(chan->name);
			leave_channel(ptr, chan, usr, cmds);
			free(cmds[0]);
		}
		chan = chan->next;
	}
	close(usr->fd);
	remove_user(((server_t *)ptr)->chan, usr);
}