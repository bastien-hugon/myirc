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
*@brief Check if an user exists
*
*@param usr The user linked list
*@param nick The nickname to find
*@return true The nickname is already in uses
*@return false The nickname doesn't exists
*/
bool user_exist(users_t *usr, char *nick)
{
	users_t *tmp = usr;

	while (tmp) {
		if (tmp->nick && !strcasecmp(nick, tmp->nick))
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

/**
*@brief Check if an user exists
*
*@param usr The user linked list
*@param nick The nick to search
*@return users_t* The user found
*/
users_t *user_exists(users_t *usr, char *nick)
{
	users_t *tmp = usr;

	while (tmp) {
		if (tmp->nick && !strcasecmp(nick, tmp->nick))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

/**
*@brief Command NICK
*
*@param srv The server_t struct
*@param usr The user who called it
*@param cmd All the cmd called
*/
void cmd_nick(void *ptr, users_t *usr, char **cmd)
{
	server_t *srv = ptr;
	char msg[50] = { 0 };

	if (cmd[1] == NULL) {
		sprintf(msg, REPL_461, "NICK");
		send_message(usr, msg);
	} else if (user_exist(srv->chan->users, cmd[1])) {
		sprintf(msg, REPL_433, cmd[1]);
		send_message(usr, msg);
	} else
		usr->nick = strdup(cmd[1]);
}