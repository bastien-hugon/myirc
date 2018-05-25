/*
** EPITECH PROJECT, 2018
** MyIRC - Server
** File description:
** Remove a channel
*/

/**
*@brief Remove a channel from the server
*
*@file remove_channel.c
*@author Hugon Bastien
*@date 24-05-2018
*/
#include "server.h"

/**
*@brief Remove a channel from the server
*
*@param srv The main server_t struct
*@param chan The chan to delete
*/
void remove_channel(server_t *srv, chan_t *chan)
{
	chan_t *tmp = srv->chan;
	chan_t *to_free;

	while (tmp->next->name != chan->name)
		tmp = tmp->next;
	to_free = tmp->next;
	tmp->next = tmp->next->next;
	free(to_free);
}