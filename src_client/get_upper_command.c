/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** get_upper_command
*/

#include "client.h"

char *get_upper_command(char **command_line, char *line)
{
	char *command;

	asprintf(&command, "%s %s\r\n", strtoupper(command_line[0] +\
	1), (line + strlen(command_line[0])));
	return (command);
}