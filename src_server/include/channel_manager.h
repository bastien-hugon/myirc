/*
** EPITECH PROJECT, 2018
** MyIRC - Server
** File description:
** Channel Manager Header
*/

#ifndef CHANNEL_MANAGER_H_
	#define CHANNEL_MANAGER_H_

	/**
	*@brief Channel Manager Header
	*
	*@file channel_manager.h
	*@author Hugon Bastien
	*@date 07-05-2018
	*/
	#include "server.h"

	bool join_channel(server_t *srv, int fd, char *chan_name);
	chan_t *create_channel(char *);
	void add_channel(server_t *srv, chan_t *chan);
	void push_user_to_chan(users_t *usr, chan_t *chan);

#endif /* !CHANNEL_MANAGER_H_ */
