/*
** EPITECH PROJECT, 2018
** TU
** File description:
** Error Handlinig
*/

#include "criterion/criterion.h"
#include "server.h"

Test(error_handling, error_handling_1)
{
	char *av[] = {"./server", "4242", "4141"};
	bool ret = check_param(3, av);

	cr_assert(ret == false, "Bad Error Handling");
}

Test(error_handling, error_handling_2)
{
	char *av[] = {"./server", "4242"};
	bool ret = check_param(2, av);

	cr_assert(ret == true, "Bad Error Handling");
}