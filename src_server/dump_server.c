/*
** EPITECH PROJECT, 2018
** MyIRC - Server
** File description:
** Dump server for debug
*/

#include "server.h"

/**
*@brief Display the current channel content
*
*@param chan The chan_t struct to display
*/
void dump_channel(chan_t *chan)
{
	users_t *tmp = chan->users;

	while (tmp) {
		printf("\t- Nickname: %s, FD: %d\n", tmp->nick, tmp->fd);
		tmp = tmp->next;
	}
}

/**
*@brief Display the current status of the entire server
*
*@param srv The server_t struct
*/
void dump_server(server_t *srv)
{
	chan_t *tmp = srv->chan;

	printf("=========\n\nServer running on port: %d\n", srv->port);
	printf("Users connected: %d\n\n=========\n\n", srv->nb_connect);
	while (tmp) {
		printf("Chan: %s\n", tmp->name);
		dump_channel(tmp);
		tmp = tmp->next;
	}
}