/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** free_tab
*/

/**
* @brief Essentials funnction to free a char**
*
* @file free_tab.c
* @author Vivies Antoine
* @date 24-05-2018
*/
#include "client.h"

/**
* @brief Permit to know the lenght of a char **
*
* @file free_tab.c
* @author Vivies Antoine
* @date 24-05-2018
*/
int strlen_tab(char **tab)
{
    int i;
    for (i = 0; tab[i] != NULL; i++);
    return (i);
}

/**
* @brief Permit to free a char **
*
* @file free_tab.c
* @author Vivies Antoine
* @date 24-05-2018
*/
void free_tab(char **tab)
{
    int i = strlen_tab(tab);
    while (i != 0) {
	free(tab[i]);
	i--;
    }
    free(tab);
}