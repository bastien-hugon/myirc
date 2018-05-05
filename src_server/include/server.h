/*
** EPITECH PROJECT, 2018
** MyIRC - Server
** File description:
** Server Header
*/

#ifndef SERVER_H_
	#define SERVER_H_

	/**
	* @brief Server Header
	*
	* @file server.h
	* @author Hugon Bastien
	* @date 05-05-2018
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

	#undef EXIT_FAILURE
	#define EXIT_FAILURE (84)

	/**
	* @struct users_t
	* @brief Structure d'utilisateurs.
	*
	* Contient toutes les informations d'un utilisateur
	* Liste chainnée d'utilisateurs
	*/
	typedef struct users_s
	{
		char *nick;
		int fd;
		struct users_s *next;
	} users_t;

	/**
	* @struct chan_t
	* @brief Structure d'un channel.
	*
	* Contient toutes les informations d'un channel
	* Liste chainnée ed channels
	*/
	typedef struct chan_s
	{
		char *name;
		users_t *users;
		struct chan_s *next;
	} chan_t;

	/**
	* @struct socket_t
	* @brief Structure qui contient toutes informations du socket.
	*/
	typedef struct socket_s
	{
		int s_fd;
		struct sockaddr_in s_s_in;
		socklen_t c_size;
	} socket_t;

	/**
	* @struct server_t
	* @brief Structure générale du server.
	*/
	typedef struct server_s
	{
		int nb_connect;
		int port;
		socket_t sock;
		chan_t *chan;
	} server_t;

	#include "error_handling.h"
	#include "init.h"

#endif