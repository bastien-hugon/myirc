/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** server
*/

/**
* @brief server function
*
* @file server.c
* @author Vivies Antoine
* @date 20-05-2018
*/
#include "client.h"

/**
* @brief Permit to fill the client_t struct and establish connection
* with server
*
* @file server.c
* @author Vivies Antoine
* @date 20-05-2018
*/
client_t *connection_to_new_serv(char *command_line, client_t *client)
{
	char **addr_and_ip = explode(command_line, ":");

	client->ip = strdup(addr_and_ip[0]);
	client->port = addr_and_ip[1] ? atoi(addr_and_ip[1]) : 6667;
	if (client->port == 0) {
		printf("Bad Port\n");
		exit(EXIT_FAILURE);
	}
	free_tab(addr_and_ip);
	create_socket(client);
	connection(client);
	return (client);
}

/**
* @brief Permit to disconnect to the server and then connect to the new
*
* @file server.c
* @author Vivies Antoine
* @date 20-05-2018
*/
client_t *disconnect_from_server(client_t *client, char *command)
{
	close(client->fd_server);
	if (client->channel)
		free(client->channel);
	if (client->ip)
		free(client->ip);
	return (connection_to_new_serv(command, client));
}

/**
* @brief Permit to execute server
*
* @file server.c
* @author Vivies Antoine
* @date 20-05-2018
*/
char *server(client_t *client, char **command_line, char *line)
{
	(void)line;
	client = disconnect_from_server(client, command_line[1]);
	return (NULL);
}