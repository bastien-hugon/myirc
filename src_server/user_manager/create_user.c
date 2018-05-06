/*
** EPITECH PROJECT, 2018
** MyIRC - Server
** File description:
** Create User
*/

/**
*@brief Create user and initialise him
*
*@file create_user.c
*@author Hugon Bastien
*@date 06-05-2018
*/
#include "server.h"

/**
*@brief Create a user object
*
*@return users_t* The new created user
*/
users_t *create_user(void)
{
	users_t *user = malloc(sizeof(users_t));

	if (!user)
		exit(EXIT_FAILURE);
	user->next = NULL;
	user->nick = NULL;
	user->size = sizeof(user->s_in);
	return (user);
}