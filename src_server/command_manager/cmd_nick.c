/*
** EPITECH PROJECT, 2018
** MyIRC - Server
** File description:
** Command Nick
*/

/**
*@brief Set the user logged in
*
*@file cmd_nick.c
*@author Hugon Bastien
*@date 14-05-2018
*/
#include "server.h"

/**
*@brief Cheack if an user exists
*
*@param usr The user linked list
*@param nick The nickname to find
*@return true The nickname is already in uses
*@return false The nickname doesn't exists
*/
bool user_exist(users_t *usr, char *nick)
{
	users_t *tmp = usr;

	while (usr) {
		if (!strcasecmp(nick, tmp->nick))
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

/**
*@brief Command NICK
*
*@param srv The server_t struct
*@param usr The user who called it
*@param cmd All the cmd called
*/
void cmd_nick(server_t *srv, users_t *usr, char **cmd)
{
	char msg[50];

	if (cmd[1] == NULL) {
		sprintf(msg, REPL_461, "NICK")
		send_message(usr, msg);
	} else if (user_exist(srv->chan->users, cmd[1])) {
		sprintf(msg, REPL_433, cmd[1]);
		send_message(usr, msg);
	} else
		usr->nick = strdup(cmd[1]);
}