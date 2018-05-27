/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** test_init_fct_ptr
*/

#include "criterion/criterion.h"
#include "client.h"

Test(init_fct_ptr, init_fct_ptr_1)
{
	command_ptr *ptr = init_fct_ptr();

	cr_assert(ptr != NULL, "Bad init");
}

Test(init_tab_ptr, init_tab_ptr_2)
{
	char **tab = init_tab_ptr();

	cr_assert(*tab != NULL, "Bad init");
}