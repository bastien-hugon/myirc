/*
** EPITECH PROJECT, 2018
** MyFTP - Server
** File description:
** Init Server
*/

#include "server.h"

void init_server(server_t *srv, int port)
{
	struct protoent *pe = getprotobyname("TCP");

	srv->port = port;
	if ((srv->sock.s_fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
		exit(error_msg("Cannot create socket"));
	srv->sock.s_s_in.sin_family = AF_INET;
	srv->sock.s_s_in.sin_port = htons(port);
	srv->sock.s_s_in.sin_addr.s_addr = INADDR_ANY;
	if (bind(srv->sock.s_fd, (const struct sockaddr *) \
	&(srv->sock.s_s_in), sizeof(srv->sock.s_s_in)))
		exit(close_and_msg(srv, "Cannot bind socket"));
	if (listen(srv->sock.s_fd, 100))
		exit(close_and_msg(srv, "Cannot listen"));
}