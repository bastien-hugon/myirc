/*
** EPITECH PROJECT, 2018
** MyIRC - Server
** File description:
** Socket Manager
*/

#ifndef SOCKET_MANAGER_H_
	#define SOCKET_MANAGER_H_

	/**
	*@brief Socket Manager Header
	*
	*@file socket_manager.h
	*@author Hugon Bastien
	*@date 06-05-2018
	*/
	#include "server.h"

	void socket_manager(server_t *srv);
	void call_worker(server_t *srv, int fd);
	bool cb_add_data(users_t *usr, char *buff);

#endif /* !SOCKET_MANAGER_H_ */
