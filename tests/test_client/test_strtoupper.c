/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** test_strtoupper
*/

#include "criterion/criterion.h"
#include "client.h"

Test(strtoupper, strtoupper_1)
{
    char string[17] = {"thanks criterion"};
	char *str = strtoupper(string);

	cr_assert(!strcmp(str, "THANKS CRITERION"), "Bad init");
}