/*
** EPITECH PROJECT, 2018
** MyIRC - Server
** File description:
** All users getter
*/

/**
*@brief All users' getters
*
*@file get_users.c
*@author Hugon Bastien
*@date 07-05-2018
*/
#include "server.h"

/**
*@brief Pull the user in chan by fd object
*
*@param chan The channel to search in
*@param fd The user's fd to find
*@return users_t* The user's object
*/
users_t *pull_user_in_chan_by_fd(chan_t *chan, int fd)
{
	users_t *tmp_user = NULL;
	users_t *current = chan->users;

	while (current) {
		if (current->fd == fd) {
			(tmp_user) ? (tmp_user->next = current->next) : \
			(chan->users = current->next);
			current->next = NULL;
			return (current);
		}
		tmp_user = current;
		current = current->next;
	}
	return (NULL);
}

/**
*@brief Get the user by fd object
*
*@param srv Main server_t struct
*@param fd The user fd
*@return users_t* The user_t corresponding user
*/
users_t *get_user_by_fd(server_t *srv, int fd)
{
	chan_t *tmp_chan = srv->chan;
	users_t *tmp_usr;

	while (tmp_chan) {
		if ((tmp_usr = pull_user_in_chan_by_fd(tmp_chan, fd)))
			return (tmp_usr);
		tmp_chan = tmp_chan->next;
	}
	return (NULL);
}