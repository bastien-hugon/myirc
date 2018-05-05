/*
** EPITECH PROJECT, 2018
** MyIRC - Server
** File description:
** Print Message - Error Handling
*/

/**
* @brief Print message file
*
* @file print_messages.c
* @author Hugon Bastien
* @date 05-05-2018
*/
#include "server.h"

/**
* @brief Display message on error output
*
* @param msg The message to print
* @return true Never
* @return false Always returned
*/
bool error_msg(char *msg)
{
	fprintf(stderr, "MyIRC: %s\n", msg);
	return (false);
}

/**
* @brief Close the server's fd and display a message on error output
*
* @param srv Current server structure to close the server fd
* @param msg The message to print
* @return int Return EXIT_FAILURE (84)
*/
int close_and_msg(server_t *srv, char *msg)
{
	close(srv->sock.s_fd);
	fprintf(stderr, "MyIRC: %s\n", msg);
	return (EXIT_FAILURE);
}

/**
* @brief Display the program's usage and exit
*/
void print_help(void)
{
	printf("USAGE: ./server port");
	exit(EXIT_SUCCESS);
}