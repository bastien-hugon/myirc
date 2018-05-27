/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** init_fct_ptr
*/

/**
* @brief Fill tabs for specials commands
*
* @file init_fct_ptr.c
* @author Vivies Antoine
* @date 20-05-2018
*/

#include "client.h"

/**
* @brief Fill function ptr with the name of special command
*
* @file init_fct_ptr.c
* @author Vivies Antoine
* @date 20-05-2018
*/
command_ptr *init_fct_ptr()
{
	command_ptr *ptr = malloc(sizeof(*ptr) * 6);

	if (ptr == NULL)
		return (NULL);
	ptr[0] = join;
	ptr[1] = nick;
	ptr[2] = server;
	ptr[3] = quit;
	ptr[4] = msg;
	ptr[5] = NULL;
	return (ptr);
}

/**
* @brief Fill tab with the name of special command
*
* @file init_fct_ptr.c
* @author Vivies Antoine
* @date 20-05-2018
*/
char **init_tab_ptr()
{
	char **tab = malloc(sizeof(char *) * 6);

	if (tab == NULL)
		return (NULL);
	tab[0] = strdup("/JOIN");
	tab[1] = strdup("/NICK");
	tab[2] = strdup("/SERVER");
	tab[3] = strdup("/QUIT");
	tab[4] = strdup("/MSG");
	tab[5] = NULL;
	return (tab);
}