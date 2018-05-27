/*
** EPITECH PROJECT, 2018
** TU
** File description:
** Error Handlinig
*/

#include "criterion/criterion.h"
#include "server.h"

Test(explode, explode_1)
{
	char **tab = explode("Toto le bulot ", " ");

	cr_assert(tab[0] && tab[1] && tab[2] && !tab[3], "Bad explode");
}