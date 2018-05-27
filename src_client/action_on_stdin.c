/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** action_on_stdin
*/

/**
* @brief Permit to convert command into RFC command and send it to server
*
* @file action_on_stdin.c
* @author Vivies Antoine
* @date 21-05-2018
*/

#include "client.h"

/**
* @brief Permit to send action to serv
*
* @file action_on_stdin.c
* @author Vivies Antoine
* @date 21-05-2018
*/
void exec_to_serv(client_t *client, char **command_line, char *line)
{
	char *command;
	command_ptr *cmd_ptr = init_fct_ptr();
	char **tab_command = init_tab_ptr();

	if (command_line[0][0] != '/') {
		asprintf(&command, "PRIVMSG %s %s\r\n", client->channel, line);
	}
	else
		command = get_upper_command(command_line, line);
	for (int i = 0; tab_command[i] != NULL; i++) {
		if (!strcmp(tab_command[i], command_line[0])) {
			command = cmd_ptr[i](client, command_line, line);
			if (command == NULL)
				return ;
			break;
		}
	}
	send(client->fd_server, command, strlen(command), MSG_EOR);
	free(command);
}

/**
* @brief Permit to do an action on stdin
*
* @file action_on_stdin.c
* @author Vivies Antoine
* @date 20-05-2018
*/
void action_on_stdin(client_t *client)
{
	char buff[1025];
	int nb_read;
	char **command_line;

	fgets(buff, 1025, stdin);
	if (buff[0] == '\n')
		return ;
	nb_read = strlen(buff);
	strtok(buff, "\n");
	command_line = explode(buff, " \t");
	if (nb_read > 1024 || nb_read == 0) {
		printf("Command too long or bad read\n");
		exit(EXIT_FAILURE);
	}
	exec_to_serv(client, command_line, buff);
	free_tab(command_line);
}