/*
** EPITECH PROJECT, 2018
** MyIRC - Server
** File description:
** Call worker
*/

/**
*@brief Call wanted commands or send message
*
*@file call_worker.c
*@author Hugon Bastien
*@date 06-05-2018
*/
#include "server.h"

/**
*@brief Parse message and call functions or write message in the good channel
*
*@param srv Main server_t struct
*@param fd The client's fd who sent a message
*/
void call_worker(server_t *srv, int fd)
{
	printf("Something received from fd: %d\n", fd);
	(void)srv;
}