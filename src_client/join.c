/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** join
*/

/**
* @brief join function
*
* @file join.c
* @author Vivies Antoine
* @date 20-05-2018
*/

#include "client.h"

/**
* @brief Permit to execute join
*
* @file join.c
* @author Vivies Antoine
* @date 20-05-2018
*/
char *join(client_t *client, char **command_line, char *line)
{
	char *command = get_upper_command(command_line, line);
	char **channels = explode((line + 5), ", ");

	(void)client;
	for (int i = 0; channels[i] != NULL ; i++) {
		if ((!strstr(channels[i], "#") && !strstr(channels[i], "&")) && \
		channels[i][0] != '0') {
			printf("%s is not a valid channel\n", channels[i]);
		}
	}
	free_tab(channels);
	return (command);
}