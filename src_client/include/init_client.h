/*
** EPITECH PROJECT, 2018
** MyIRC - Client
** File description:
** Initialisation
*/

#ifndef INIT_H_
	#define INIT_H_

	/**
	*@brief Initialisation Connection
	*
	*@file init.h
	*@author Vivies Antoine
	*@date 07-05-2018
	*/
	#include "client.h"

	void connection(client_t *client);
	void create_socket(client_t *client);

#endif /* !INIT_H_ */
