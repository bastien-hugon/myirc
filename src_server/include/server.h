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
	#include <time.h>

	#include <sys/socket.h>
	#include <netdb.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>
	#include <sys/epoll.h>

	#undef EXIT_FAILURE
	#define EXIT_FAILURE (84)

	#define MAX_EVENTS (100)
	#define BUFF_SIZE (1024)
	#define BUFF_LEN(s, e) ((s < e) ? (e - s + 1) : (BUFF_SIZE - s + e + \
	1))

	/**
	*@struct circular_buffer_t
	*@brief Structure de buffer circulaire
	*
	*Contient le buffer circulaire d'un utilisateur
	*/
	typedef struct circular_buffer_s
	{
		char buffer[BUFF_SIZE];
		int start;
		int end;
	} circular_buffer_t;

	/**
	* @struct users_t
	* @brief Structure d'utilisateurs.
	*
	* Contient toutes les informations d'un utilisateur
	* Liste chainnée d'utilisateurs
	*/
	typedef struct users_s
	{
		int fd;
		char *nick;
		bool is_logged;
		struct sockaddr_in s_in;
		char *c_ip;
		socklen_t size;
		circular_buffer_t buff;
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
	} socket_t;

	typedef void (*fptr)(void *, users_t *, char **);
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
		fptr *cmds;
		char **cmd_name;
		char date[15];
		struct epoll_event ev;
		struct epoll_event events[MAX_EVENTS];
		int epollfd;
	} server_t;


	#include "error_handling.h"
	#include "init.h"
	#include "socket_manager.h"
	#include "user_manager.h"
	#include "channel_manager.h"
	#include "command_manager.h"
	#include "messages.h"

	void dump_server(server_t *srv);

#endif