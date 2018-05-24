/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** read_on_fds
*/

#include "client.h"

/**
* @brief Permit to know activities of file descriptor
*
* @file read_on_fds.c
* @author Vivies Antoine
* @date 14-05-2018
*/
void read_on_fds(client_t *client)
{
	fd_set fds;
	int sd = client->fd_server;
	int maxfd = (sd > STDIN)?sd:STDIN;

	for (;;) {
		FD_ZERO(&fds);
		FD_SET(sd, &fds);
		FD_SET(STDIN, &fds);
		if (select(maxfd+1, &fds, NULL, NULL, NULL) == -1) {
			printf("Problem with select\n");
			exit(EXIT_FAILURE);
		}
		if (FD_ISSET(STDIN, &fds)){
			action_on_stdin(client);
		}
		if (FD_ISSET(sd, &fds)) {
			action_on_server_fd(client);
		}
	}
}