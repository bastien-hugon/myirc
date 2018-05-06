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
			./src_server/error_handling/check_param.c \
			./src_server/error_handling/print_messages.c \
			./src_server/init/init_server.c \
			./src_server/init/init_epoll.c \
			./src_server/socket_manager/socket_manager.c \
			./src_server/socket_manager/call_worker.c \
			./src_server/user_manager/create_user.c
			

SRCS_CLIENT	= 

SRCS_TESTS	= 

OBJS_SERVER	= $(SRCS_SERVER:.c=.o)

CFLAGS = -I ./src_server/include/ -I./src_client/include/
CFLAGS += -W -Wall -Wextra

all: $(SERVER)

$(SERVER): $(OBJS_SERVER)
	$(CC) $(OBJS_SERVER) -o $(SERVER) $(LDFLAGS)

unit_tests: $(OBJS_TESTS)
	$(CC) $(OBJS_TESTS) -o unit_tests -lcriterion -lgcov --coverage
	@./unit_tests

doxygen:
	@doxygen
	@chromium-browser ./bonus/doc/html/index.html

clean:
	$(RM) $(OBJS_SERVER)

fclean: clean
	$(RM) $(SERVER)
	$(RM) -Rf bonus/doc/

re: fclean all

.PHONY: all clean fclean re
