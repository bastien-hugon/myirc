/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** waiting_for_server
*/

#include "client.h"

void fill_client_struct(char **command_line, client_t *client)
{
	char **addr_and_ip = explode(command_line[1], ":");

	client->ip = strdup(addr_and_ip[0]);
	client->port = addr_and_ip[1] ? atoi(addr_and_ip[1]) : 6667;
	if(client->port == 0) {
		printf("Bad Port\n");
		exit(EXIT_FAILURE);
	}
	free_tab(addr_and_ip);
	free_tab(command_line);
	create_socket(client);
	connection(client);
	read_on_fds(client);
}

void waiting_for_server()
{
	char buff[1025] = { 0 };
	char **command_line;
	client_t client;

	for (;;) {
		fgets(buff, 1025, stdin);
		if (buff == NULL) {
			printf("Bad Read\n");
			exit(EXIT_FAILURE);
		}
		command_line = explode(buff, " \t");
		if (strstr("/server", command_line[0]))
			fill_client_struct(command_line, &client);
		else
			printf("/server ip:port\n");
	}
	disconnect(&client);
}