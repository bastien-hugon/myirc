/*
** EPITECH PROJECT, 2018
** MyIRC - Server
** File description:
** Command User
*/

/**
*@brief Set the nickname of a user
*
*@file cmd_user.c
*@author Hugon Bastien
*@date 14-05-2018
*/
#include "server.h"

/**
*@brief Command USER
*
*@param srv The server_t struct
*@param usr The user who called it
*@param cmd All the cmd called
*/
void cmd_user(void *ptr, users_t *usr, char **cmd)
{
	(void)ptr;
	char msg[50] = { 0 };

	for (int i = 0; i < 5; i++) {
		if (cmd[i] == NULL) {
			sprintf(msg, REPL_461, "USER");
			send_message(usr, msg);
			return ;
		}
	}
	usr->is_logged = true;
}