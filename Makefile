##
## EPITECH PROJECT, 2018
## MyIRC
## File description:
## Makefile
##

SERVER	= server

CLIENT	= client

CC	= gcc

RM	= rm -f

SRCS_SERVER	=	./src_server/main.c \
			./src_server/dump_server.c \
			./src_server/error_handling/check_param.c \
			./src_server/error_handling/print_messages.c \
			./src_server/init/init_server.c \
			./src_server/init/init_epoll.c \
			./src_server/socket_manager/socket_manager.c \
			./src_server/socket_manager/call_worker.c \
			./src_server/socket_manager/circular_buffer.c \
			./src_server/user_manager/create_user.c \
			./src_server/user_manager/get_users.c \
			./src_server/user_manager/is_logged.c \
			./src_server/channel_manager/create_channel.c \
			./src_server/channel_manager/join_channel.c \
			./src_server/channel_manager/remove_channel.c \
			./src_server/command_manager/exec_user_command.c \
			./src_server/command_manager/send_message.c \
			./src_server/command_manager/explode.c \
			./src_server/command_manager/cmd_user.c \
			./src_server/command_manager/cmd_nick.c \
			./src_server/command_manager/cmd_join.c \
			./src_server/command_manager/cmd_quit.c \
			./src_server/command_manager/cmd_part.c \
			./src_server/command_manager/free_tab.c \
			./src_server/command_manager/create_commands.c

SRCS_CLIENT	= 

SRCS_TESTS	=	./tests/test_server/test_error_handling.c \
			./src_server/dump_server.c \
			./src_server/error_handling/check_param.c \
			./src_server/error_handling/print_messages.c \
			./src_server/init/init_server.c \
			./src_server/init/init_epoll.c \
			./src_server/socket_manager/socket_manager.c \
			./src_server/socket_manager/call_worker.c \
			./src_server/user_manager/create_user.c \
			./src_server/user_manager/get_users.c \
			./src_server/channel_manager/create_channel.c \
			./src_server/channel_manager/join_channel.c

OBJS_SERVER	= $(SRCS_SERVER:.c=.o)

OBJS_TESTS	= $(SRCS_TESTS:.c=.o)

CFLAGS = -I ./src_server/include/ -I./src_client/include/
CFLAGS += -W -Wall -Wextra

all: $(SERVER)

$(SERVER): $(OBJS_SERVER)
	$(CC) $(OBJS_SERVER) -o $(SERVER) $(LDFLAGS)

unit_tests: $(OBJS_TESTS)
	$(CC) -lcriterion -fprofile-arcs -ftest-coverage -fPIC --coverage $(CFLAGS) $(SRCS_TESTS) -o unit_tests
	@./unit_tests
	gcovr -r .

doxygen:
	@doxygen
	@chromium-browser ./bonus/doc/html/index.html

clean:
	$(RM) $(OBJS_SERVER)
	$(RM) *.g*

fclean: clean
	$(RM) $(SERVER)
	$(RM) unit_tests
	$(RM) -Rf bonus/doc/

re: fclean all

.PHONY: all clean fclean re