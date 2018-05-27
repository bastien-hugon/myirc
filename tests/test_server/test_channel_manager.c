/*
** EPITECH PROJECT, 2018
** TU
** File description:
** Error Handling
*/

#include "criterion/criterion.h"
#include "server.h"

Test(channel_manager, channel_manager_1)
{
	server_t srv;
	chan_t *chan;
	users_t *usr = create_user();

	srand(time(0));
	usr->fd = 12;
	init_server(&srv, rand() % 4242 + 4242);
	chan = create_and_add_chan(&srv, "#toto");
	cr_assert(!strcmp(chan->name, "#toto"), "Bad channel management");
	(&srv)->chan->users = usr;
	join_channel(&srv, 12, "#toto");
	cr_assert(is_on_chan((&srv)->chan, 12), "Bad channel management");
}