/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** create_socket
*/

/**
* @brief Permit socket creation
*
* @file create_socket.c
* @author Vivies Antoine
* @date 07-05-2018
*/
#include "client.h"

/**
* @brief Client socket creation
*
* @file create_socket.c
* @author Vivies Antoine
* @date 07-05-2018
*/
void create_socket(client_t *client)
{
	client->pe = getprotobyname("TCP");
	if (!client->pe)
		exit(EXIT_FAILURE);
	client->fd_server = socket(AF_INET, SOCK_STREAM, client->pe->p_proto);
	if (client->fd_server == -1)
		exit(EXIT_FAILURE);
	client->s_in.sin_family = AF_INET;
	client->s_in.sin_port = htons(client->port);
	client->s_in.sin_addr.s_addr = inet_addr(client->ip);
}