/*
** EPITECH PROJECT, 2018
** MyIRC - Server
** File description:
** Create Channel
*/

/**
*@brief Create a channel
*
*@file create_channel.c
*@author Hugon Bastien
*@date 07-05-2018
*/
#include "server.h"

/**
*@brief Add a channel to the channel linked list
*
*@param srv Main server_t struct
*@param chan The chan_t to add in the linked list
*/
void add_channel(server_t *srv, chan_t *chan)
{
	chan_t *tmp = srv->chan;

	if (!tmp) {
		srv->chan = chan;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = chan;
}

/**
*@brief Create a channel object
*
*@return chan_t* the channel created
*/
chan_t *create_channel(char *name)
{
	chan_t *chan = malloc(sizeof(chan_t));

	if (!chan)
		exit(EXIT_FAILURE);
	chan->name = strdup(name);
	chan->users = NULL;
	chan->next = NULL;
	return (chan);
}

/**
*@brief Create and add chan object to list
*
*@param srv The main server_t struct
*@param name Chan name
*@return chan_t* The created channel
*/
chan_t *create_and_add_chan(server_t *srv, char *name)
{
	chan_t *chan = create_channel(name);

	add_channel(srv, chan);
	return (chan);
}