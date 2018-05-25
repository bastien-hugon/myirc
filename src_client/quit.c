/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** quit
*/

/**
* @brief quit function
*
* @file quit.c
* @author Vivies Antoine
* @date 20-05-2018
*/

#include "client.h"

/**
* @brief Permit to execute quit
*
* @file quit.c
* @author Vivies Antoine
* @date 20-05-2018
*/
char *quit(client_t *client, char **command_line, char *line)
{
	(void)command_line;
	(void)line;
	disconnect(client);
	return (NULL);
}