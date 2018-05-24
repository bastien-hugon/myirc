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
	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <stdbool.h>
	#include <string.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <signal.h>

	#include <sys/socket.h>
	#include <netdb.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>
	#include <sys/epoll.h>
	#include "server.h"

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

	#include "init_client.h"

#endif