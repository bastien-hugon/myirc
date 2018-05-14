/*
** EPITECH PROJECT, 2018
** MyIRC - Server
** File description:
** Command Manager
*/

#ifndef COMMAND_MANAGER_H_
	#define COMMAND_MANAGER_H_

	/**
	*@brief Command manager
	*
	*@file command_manager.h
	*@author Hugon Bastien
	*@date 14-05-2018
	*/
	#include "server.h"

	#define NB_CMDS (1)

	typedef enum
	{
		C_NICK, \
		C_USER
	} cmds_e;

	typedef bool (*fptr)(server_t *, users_t *, char **);
	fptr *create_cmds(void);
	void exec_user_command(server_t *srv, users_t *usr);

#endif /* !COMMAND_MANAGER_H_ */
