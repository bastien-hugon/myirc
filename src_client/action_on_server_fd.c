/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** action_on_server_fd
*/

/**
* @brief Permit to write returns codes from the server
*
* @file action_on_server_fd.c
* @author Vivies Antoine
* @date 14-05-2018
*/

#include "client.h"

void interpretation_of_returns(client_t *client, char *buff)
{
	char **command = explode(buff, " \t");

	if (strstr(buff, "JOIN")) {
		client->channel = strdup(command[2]);
	}
	free_tab(command);
}

/**
* @brief Permit to write server codes
*
* @file action_on_server_fd.c
* @author Vivies Antoine
* @date 14-05-2018
*/
void write_server_returns_code(client_t *client)
{
	char buff[1025] = { 0 };
	int nb_read = read(client->fd_server, buff, 1025);

	nb_read = strlen(buff);
	buff[nb_read] = '\0';
	if (nb_read == 0) {
		printf("Bad read\n");
		exit(EXIT_FAILURE);
	} else {
		printf("%s", buff);
		interpretation_of_returns(client, buff);
	}
}