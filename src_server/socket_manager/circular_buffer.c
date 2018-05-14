/*
** EPITECH PROJECT, 2018
** MyIRC - Server
** File description:
** Circular Buffer Functions
*/

/**
*@brief All functions related to the circular buffer uses
*
*@file circular_buffer.c
*@author Hugon Bastien
*@date 11-05-2018
*/
#include "server.h"

/**
*@brief Add data to the circular buffer of an user
*
*@param usr The current user
*@param buff The data to add
*@return true If the data is fully read
*@return false If the data isn't fully read
*/
bool cb_add_data(users_t *usr, char *buff)
{
	for (int i = 0; (unsigned int) i < strlen(buff); i++) {
		usr->buff.buffer[(usr->buff.start + i) % BUFF_SIZE] = \
		buff[i];
		usr->buff.end = (usr->buff.start + i) % BUFF_SIZE;
	}
	return (strstr(buff, "\r\n") != NULL || strstr(buff, "\n") != NULL);
}