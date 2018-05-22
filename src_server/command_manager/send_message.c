/*
** EPITECH PROJECT, 2018
** MyIRC - Server
** File description:
** Send Message to an user
*/

/**
*@brief Send a message to a specific user
*
*@file send_message.c
*@author Hugon Bastien
*@date 14-05-2018
*/
#include "server.h"

/**
*@brief Send a message to a specific user
*
*@param usr The user to send the message
*@param msg The message to send
*/
void send_message(users_t *usr, char *msg)
{
	dprintf(usr->fd, "%s\n", msg);
}