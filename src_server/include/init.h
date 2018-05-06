/*
** EPITECH PROJECT, 2018
** MyIRC - Server
** File description:
** Initialisation
*/

#ifndef INIT_H_
	#define INIT_H_

	/**
	*@brief Initialisation Header
	*
	*@file init.h
	*@author Hugon Bastien
	*@date 05-05-2018
	*/
	#include "server.h"

	void init_server(server_t *srv, int port);
	void init_epoll(server_t *srv);

#endif /* !INIT_H_ */
