/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** strtoupper
*/

/**
* @brief lowercase to uppercase
*
* @file strtoupper.c
* @author Vivies Antoine
* @date 07-05-2018
*/

#include "client.h"

/**
* @brief Permit to put a char * in uppercase
*
* @file strtoupper.c
* @author Vivies Antoine
* @date 07-05-2018
*/
char *strtoupper(char *s)
{
	for (int i = 0; s[i]; i++)
		s[i] = toupper((unsigned char)s[i]);
	return (s);
}