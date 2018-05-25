/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** nick
*/

/**
* @brief Nick function
*
* @file nick.c
* @author Vivies Antoine
* @date 20-05-2018
*/

#include "client.h"

/**
* @brief Permit to execute nick
*
* @file nick.c
* @author Vivies Antoine
* @date 20-05-2018
*/
char *nick(client_t *client, char **command_line, char *line)
{
	char *command = get_upper_command(command_line, line);
	char *command_user;

	send(client->fd_server, command, strlen(command), MSG_EOR);
	free(command);
	asprintf(&command_user, "USER %s %s %s :realname\r\n", command_line[1]
	, command_line[1], command_line[1]);
	return (command_user);
}