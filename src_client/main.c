/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** main
*/

/**
* @brief Main file call all function each time
*
* @file main.c
* @author your name
* @date 2018-05-14
*/
#include "client.h"

/**
* @brief Client main functiom
*
* @file main.c
* @author Vivies Antoine
* @date 07-05-2018
*/
int main(int ac, char **av)
{
	client_t client;

	if (ac != 3) {
		fprintf(stderr, "Bad parameter\n");
		return (EXIT_FAILURE);
	}
	client.port = atoi(av[2]);
	client.ip = strdup(av[1]);
	if (!client.ip)
		return (EXIT_FAILURE);
	create_socket(&client);
	connection(&client);
	read_on_fds(&client);
	close(client.fd_server);
	free(client.ip);
	return (0);
}