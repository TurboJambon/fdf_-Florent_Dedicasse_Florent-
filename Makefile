# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/18 16:55:07 by niragne           #+#    #+#              #
#    Updated: 2017/05/30 19:53:28 by dchirol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	FdF
CC			=	gcc
CFLAGS		=	-Werror -Wall -Wextra
CFLAGSMLX	=	-lmlx -framework OpenGL -framework AppKit

LIB_PATH	=	libft
LIB			=	$(LIB_PATH)/libft.a

INC_DIR		=	.
INCS		=	-I $(INC_DIR) -I $(LIB_PATH)

SRC_DIR		=	.
SRC			=	fdf.c \
				clean.c \
				ft_map.c \
				ft_puterr.c \
				ft_trace.c \
				info.c

OBJ_DIR		=	.

SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))


all: $(NAME)

$(NAME): lib $(OBJS)
	$(CC) $(CFLAGS) -o FdF $(OBJS) $(CFLAGSMLX) $(LIB)

lib:
	make -C $(LIB_PATH)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCS) -c -o $@ $<

clean:
	make -C $(LIB_PATH) clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re