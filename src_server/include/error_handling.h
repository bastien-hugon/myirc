/*
** EPITECH PROJECT, 2018
** MyIRC - Server
** File description:
** Error Handling
*/

#ifndef ERROR_HANDLING_H_
	#define ERROR_HANDLING_H_

	/**
	*@brief Error Handling Header
	*
	*@file error_handling.h
	*@author Hugon Bastien
	*@date 05-05-2018
	*/
	#include "server.h"

	bool error_msg(char *msg);
	bool check_param(int ac, char **av);
	void print_help(void);
	int close_and_msg(server_t *srv, char *msg);

#endif /* !ERROR_HANDLING_H_ */
