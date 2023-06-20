# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaldas <acaldas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/07 15:19:03 by acaldas           #+#    #+#              #
#    Updated: 2023/06/07 15:20:12 by acaldas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CLIENT = client
SRC_CLIENT = client.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

SERVER = server
SRC_SERVER = server.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)

LIB_PATH = ./libft/libft.a

CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L./libft -lft

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SERVER)
	$(MAKE) -C libft
	$(CC) $(OBJ_SERVER) $(LDFLAGS) -o $(SERVER)

$(CLIENT): $(OBJ_CLIENT)
	$(MAKE) -C libft
	$(CC) $(OBJ_CLIENT) $(LDFLAGS) -o $(CLIENT)

clean:
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)
	$(MAKE) clean -C libft

fclean: clean
	$(RM) $(NAME) $(SERVER) $(CLIENT)
	$(MAKE) fclean -C libft

re: fclean all
