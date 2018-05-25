/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** msg
*/

/**
* @brief msg function
*
* @file msg.c
* @author Vivies Antoine
* @date 20-05-2018
*/

#include "client.h"

/**
* @brief Permit to execute msg
*
* @file msg.c
* @author Vivies Antoine
* @date 20-05-2018
*/
char *msg(client_t *client, char **command_line, char *line)
{
	char *command;

	(void)client;
	(void)command_line;
	asprintf(&command, "PRIVMSG %s\r\n", (line + 4));
	return (command);
}