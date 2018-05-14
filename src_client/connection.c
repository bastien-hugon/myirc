/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** connection
*/

#include "client.h"

/**
* @brief connection client to server
*
* @file connection.c
* @author Vivies Antoine
* @date 07-05-2018
*/
void connection(client_t *client)
{
	if (connect(client->fd_server, (struct sockaddr *)&client->
		s_in, sizeof(client->s_in)) == -1) {
		close(client->fd_server);
		exit(EXIT_FAILURE);
	}
}