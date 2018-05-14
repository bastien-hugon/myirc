/*
** EPITECH PROJECT, 2018
** MyIRC - Server
** File description:
** Check Param
*/

/**
*@brief Error Handling - Check Params
*
*@file check_param.c
*@author Hugon Bastien
*@date 05-05-2018
*/
#include "server.h"

/**
* @brief Check the program's parameter
*
* @param ac Number of parameters
* @param av All program's parameters
* @return true If there is no error
* @return false If there is errors
*/
bool check_param(int ac, char **av)
{
	if (ac != 2)
		return (error_msg("Bad arguments."));
	if (!strcmp("-help", av[1]))
		print_help();
	if (atoi(av[1]) <= 0)
		return (error_msg("Bad arguments."));
	return (true);
}