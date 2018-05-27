/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** test_join
*/

#include "criterion/criterion.h"
#include "client.h"

Test(join, join_1)
{
    client_t client;
    char command_line[] = {"/join #Michel"};
    char *command; 

    command = join(&client, explode(command_line, " "), command_line);
    client.channel = malloc(strlen("#michel") + 1);
	cr_assert(command, "Bad init");
}

