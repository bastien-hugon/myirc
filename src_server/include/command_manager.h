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

	#define NB_CMDS (5)

	typedef enum
	{
		C_NICK, \
		C_USER, \
		C_JOIN, \
		C_QUIT, \
		C_PART
	} cmds_e;

	fptr *create_cmds(void);
	void free_tab(char **);
	char **get_cmd_names(void);
	void exec_user_command(server_t *srv, users_t *usr);
	void send_message(users_t *usr, char *msg);
	void chan_broadcast_message(chan_t *chan, char *msg);
	char **explode(char *str, char *lim);
	void leave_channel(server_t *srv, chan_t *chan, users_t *usr, \
	char **cmd);
	void cmd_user(void *, users_t *, char **);
	void cmd_nick(void *, users_t *, char **);
	void cmd_join(void *, users_t *, char **);
	void cmd_quit(void *, users_t *, char **);
	void cmd_part(void *, users_t *, char **);

#endif /* !COMMAND_MANAGER_H_ */
