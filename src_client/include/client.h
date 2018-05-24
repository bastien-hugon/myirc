/*
** EPITECH PROJECT, 2018
** MyIRC - Client
** File description:
** Client Header
*/

#ifndef CLIENT_H_
	#define CLIENT_H_

	/**
	* @brief Client Header
	*
	* @file client.h
	* @author Vivies Antoine
	* @date 07-05-2018
	*/
	#include "server.h"
	#include <ctype.h>

	#undef EXIT_FAILURE
	#define EXIT_FAILURE (84)
	#define MAX_EVENTS (100)
	#define STDIN (0)


	/**
	* @brief Client struct
	*
	* @file client.h
	* @author Vivies Antoine
	* @date 07-05-2018
	*/
	typedef struct client_s
	{
		int fd_server;
		int port;
		char *ip;
		struct sockaddr_in s_in;
		struct protoent *pe;
	}			   client_t;

	char *strtoupper(char *s);
	void create_socket(client_t *client);
	void read_on_fds(client_t *client);
	void connection(client_t *client);
	void action_on_stdin(client_t *client);
	void write_server_returns_code(client_t *client);



	#include "init_client.h"

#endif