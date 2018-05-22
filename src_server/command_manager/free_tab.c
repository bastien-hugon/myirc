/*
** EPITECH PROJECT, 2018
** MyIRC - Server
** File description:
** Free Tabs
*/

/**
*@brief Free a tab
*
*@file free_tab.c
*@author Hugon Bastien
*@date 15-05-2018
*/
#include "server.h"

/**
*@brief Free a tab
*
*@param tab The tab to free
*/
void free_tab(char **tab)
{
	for (int i = 0; tab[i]; i++)
		free(tab[i]);
	free(tab);
}