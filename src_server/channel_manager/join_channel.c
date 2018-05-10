/*
** EPITECH PROJECT, 2018
** MyIRC - Server
** File description:
** Join Channel
*/

/**
*@brief Join channels mechanics
*
*@file join_channel.c
*@author Hugon Bastien
*@date 07-05-2018
*/
#include "server.h"

/**
*@brief Get the channel object
*
*@param srv Main server_t struct
*@param chan The channel name
*@return chan_t* The chan_t struct found
*/
chan_t *get_channel(server_t *srv, char *chan)
{
	chan_t *tmp = srv->chan;

	while (tmp) {
		if (!strcmp(tmp->name, chan))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

/**
*@brief Add an user on the user's linked list of a channel
*
*@param usr The users_t object to push
*@param chan The chan_t struct
*/
void push_user_to_chan(users_t *usr, chan_t *chan)
{
	users_t *tmp = chan->users;

	usr->next = NULL;
	if (!tmp) {
		chan->users = usr;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = usr;
}

/**
*@brief Move an user to a specific channel
*
*@param srv Main server_t struct
*@param fd The user fd
*@param chan_name The channel name to join
*@return true if the channel exist and the move succeed
*@return false if the channel doesn't exists
*/
bool join_channel(server_t *srv, int fd, char *chan_name)
{
	users_t *user;
	chan_t *chan;

	if ((chan = get_channel(srv, chan_name))) {
		user = get_user_by_fd(srv, fd);
		push_user_to_chan(user, chan);
		return (true);
	}
	return (false);
}