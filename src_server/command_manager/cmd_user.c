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
*@brief Send the welcome message to the user
*
*@param srv The main server_t struct
*@param usr The user to send the message
*/
static void send_welcome_message(server_t *srv, users_t *usr)
{
	char buffer[256];

	sprintf(buffer, REPL_001, "epi", "irc");
	send_message(usr, buffer);
	send_message(usr, REPL_002);
	sprintf(buffer, REPL_003, srv->date);
	send_message(usr, buffer);
	send_message(usr, REPL_004);
	sprintf(buffer, REPL_005, srv->port);
	send_message(usr, buffer);
}

/**
*@brief Command USER
*
*@param srv The server_t struct
*@param usr The user who called it
*@param cmd All the cmd called
*/
void cmd_user(void *ptr, users_t *usr, char **cmd)
{
	char msg[50] = { 0 };

	for (int i = 0; i < 5; i++) {
		if (cmd[i] == NULL) {
			sprintf(msg, REPL_461, "USER");
			send_message(usr, msg);
			return ;
		}
	}
	usr->is_logged = true;
	send_welcome_message(ptr, usr);
}