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
*@brief Create a cmds object
*
*@return fptr* return the array of function pointers
*/
fptr *create_cmds(void)
{
	fptr *cmds = malloc(sizeof(*cmds) * (NB_CMDS + 1));

	cmds[C_NICK] = cmd_nick;
	cmds[C_USER] = cmd_user;
	return (cmds);
}