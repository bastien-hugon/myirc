/*
** EPITECH PROJECT, 2018
** MyIRC - Server
** File description:
** Execute users' commands
*/

/**
*@brief Execute users' commands
*
*@file exec_user_command.c
*@author Hugon Bastien
*@date 11-05-2018
*/
#include "server.h"

/**
*@brief Get the command object
*
*@param usr The user who get the command
*@return char* The command
*/
static char *get_command(users_t *usr)
{
	int buff_len = BUFF_LEN(usr->buff.start, usr->buff.end);
	char *cmd = malloc(sizeof(char) * (buff_len + 1));

	if (!cmd)
		exit(EXIT_FAILURE);
	cmd[buff_len] = '\0';
	for (int i = 0; i < buff_len; i++)
		cmd[i] = usr->buff.buffer[(usr->buff.start + i) % BUFF_SIZE];
	usr->buff.end++;
	usr->buff.start = usr->buff.end;
	return (cmd);
}

/**
*@brief Execute an user command's
*
*@param srv The main server_t struct
*@param usr The user who sent the command
*/
void exec_user_command(server_t *srv, users_t *usr)
{
	char *cmd = strtok(get_command(usr), "\r\n");

	free(cmd);
}