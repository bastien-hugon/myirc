/*
** EPITECH PROJECT, 2018
** MyIRC - Server
** File description:
** Commande Join
*/

/**
*@brief JOIN command
*
*@file cmd_join.c
*@author Hugon Bastien
*@date 17-05-2018
*/
#include "server.h"

/**
*@brief Join an user to a channel
*
*@param ptr The server_t struct
*@param usr The user who called this command
*@param cmd The cmd called
*/
void cmd_join(void *ptr, users_t *usr, char **cmd)
{
	server_t *srv = ptr;
	char msg[50] = { 0 };

	if (!cmd[1]) {
		sprintf(msg, REPL_461, "JOIN");
		send_message(usr, msg);
	} else if (!is_logged(usr))
		send_message(usr, msg);
	else {
		
	}
}