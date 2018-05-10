/*
** EPITECH PROJECT, 2018
** MyIRC - Server
** File description:
** User Manager Header
*/

#ifndef USER_MANAGER_H_
	#define USER_MANAGER_H_

	/**
	*@brief User Manager Header
	*
	*@file user_manager.h
	*@author Hugon Bastien
	*@date 06-05-2018
	*/
	#include "server.h"

	users_t *create_user(void);
	users_t *get_user_by_fd(server_t *srv, int fd);

#endif /* !USER_MANAGER_H_ */