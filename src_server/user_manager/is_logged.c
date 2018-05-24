/*
** EPITECH PROJECT, 2018
** MyIRC - Server
** File description:
** Is Logged
*/

/**
*@brief Knowing if an user is logged
*
*@file is_logged.c
*@author Hugon Bastien
*@date 17-05-2018
*/
#include "server.h"

/**
*@brief Knowing if an user is logged
*
*@param usr The user to verify
*@return true If the user is logged in
*@return false If the user isn't logged in
*/
bool is_logged(users_t *usr)
{
	return (usr->is_logged && (usr->nick != NULL));
}