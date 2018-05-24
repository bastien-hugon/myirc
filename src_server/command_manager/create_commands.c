/*
** EPITECH PROJECT, 2018
** MyIRC -Server
** File description:
** Create the array function pointers
*/

/**
*@brief Create the array of functions pointers
*
*@file create_commands.c
*@author Hugon Bastien
*@date 14-05-2018
*/
#include "server.h"

/**
*@brief Get the cmd_names object
*
*@return char** The array of cmd names
*/
char **get_cmd_names(void)
{
	char **cmds = malloc(sizeof(char *) * (NB_CMDS + 1));

	cmds[C_NICK] = strdup("nick");
	cmds[C_USER] = strdup("user");
	cmds[C_JOIN] = strdup("join");
	cmds[C_QUIT] = strdup("quit");
	cmds[NB_CMDS] = NULL;
	return (cmds);
}

/**
*@brief Create a cmds object
*
*@return fptr* return the array of function pointers
*/
fptr *create_cmds(void)
{
	fptr *cmds = malloc(sizeof(*cmds) * (NB_CMDS + 1));

	cmds[C_NICK] = cmd_nick;
	cmds[C_USER] = cmd_user;
	cmds[C_JOIN] = cmd_join;
	cmds[C_QUIT] = cmd_quit;
	return (cmds);
}