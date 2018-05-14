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

	#define NB_CMDS (2)

	typedef enum
	{
		C_NICK, \
		C_USER
	} cmds_e;

	fptr *create_cmds(void);
	char **get_cmd_names(void);
	void exec_user_command(server_t *srv, users_t *usr);
	void send_message(users_t *usr, char *msg);
	char **explode(char *str, char *lim);
	void cmd_user(void *, users_t *, char **);
	void cmd_nick(void *, users_t *, char **);

#endif /* !COMMAND_MANAGER_H_ */
