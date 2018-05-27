/*
** EPITECH PROJECT, 2018
** TU
** File description:
** command manager
*/

#include "criterion/criterion.h"
#include "server.h"

Test(command_manager, command_manager_1)
{
	fptr *cmds = create_cmds();
	char **cmd = get_cmd_names();

	cr_assert(cmds[NB_CMDS] == NULL, "Bad command manager");
	cr_assert(cmd[NB_CMDS] == NULL, "Bad command manager");
}