/*
** EPITECH PROJECT, 2018
** TU
** File description:
** Error Handlinig
*/

#include "criterion/criterion.h"
#include "server.h"

Test(channel_manager, channel_manager_1)
{
	chan_t *chan = create_channel("#toto");

	cr_assert(!strcmp("#toto", chan->name), "Bad channel management");
}

Test(channel_manager, channel_manager_2)
{
	server_t *srv;
	chan_t *chan;

	chan = create_and_add_chan("#toto");
	init_server(&srv, 4242);
	cr_assert(!strcmp("#toto", chan->name), "Bad channel management");
}

Test(channel_manager, channel_manager_3)
{
	server_t *srv;

	init_server(&srv, 4242);
}