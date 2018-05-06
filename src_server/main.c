/*
** EPITECH PROJECT, 2018
** MyIRC - Server
** File description:
** Main
*/

/**
* @brief Main File
*
* @file main.c
* @author Hugon Bastien
* @date 05-05-2018
*/
#include "server.h"

/**
* @brief MyIRC Server - Main function
*
* @param ac Number of parameter
* @param av Program parameters
* @return int Exit status
*/
int main(int ac, char **av)
{
	server_t srv;

	if (!check_param(ac, av))
		return (EXIT_FAILURE);
	init_server(&srv, atoi(av[1]));
	init_epoll(&srv);
	socket_manager(&srv);
	return (EXIT_SUCCESS);
}