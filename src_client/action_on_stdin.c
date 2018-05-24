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

	if (command_line[0][0] != '/') {
		command = malloc((strlen("PRIVMSG ") + strlen(line) + 1));
		command = strcpy(command, "PRIVMSG ");
		command = strcat(command, (line));
	} else if (strstr(command_line[0], "/msg")) {
		command = malloc(strlen("PRIVMSG") + strlen(line + 3));
		command = strcpy(command, "PRIVMSG");
		command = strcat(command, (line + 4));
	} else {
		command = malloc(strlen(command_line[0] + 1) + strlen(line
		 + strlen(command_line[0] + 1)));
		command = strcpy(command, strtoupper(command_line[0] + 1));
		command = strcat(command, (line + strlen(command_line[0])));
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
	FILE *standar_input = fdopen(STDIN, "r+");
	int nb_read;
	char **command_line;

	fgets(buff, 1025, standar_input);
	if (buff[0] == '\n')
		return;
	nb_read = strlen(buff);
	command_line = explode(buff, " \t");
	if (nb_read > 1024 || nb_read == 0) {
		printf("Command too long or bad read\n");
		exit(EXIT_FAILURE);
	} 
	exec_to_serv(client, command_line, buff);
	free_tab(command_line);
}