# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchirol <dchirol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/18 16:55:07 by niragne           #+#    #+#              #
#    Updated: 2017/05/29 17:42:03 by dchirol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =   fdf
CC          =   gcc 
CFLAGS      =   -lmlx -framework OpenGL -framework Appkit
LIB_PATH    =   libft
LIB         =   $(LIB_PATH)/libft.a
LIB_LINK    =   -L. $(LIB)
INC_DIR     =   includes
INCS        =   -I $(LIB_PATH) -I $(INC_DIR)
SRC_DIR     =   
SRC         =   fdf.c ft_map.c info.c ft_puterr.c clean.c ft_trace.c
OBJ_DIR     =   obj
SRCS        =   $(addprefix $(SRC_DIR), $(SRC))
OBJS        =   $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
all: obj $(NAME)
$(NAME): $(LIB) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB_LINK)
$(LIB):
	make -C $(LIB_PATH)
obj:
	mkdir -p obj
$(OBJ_DIR)/%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCS) -c -o $@ $<
clean:
	rm -f $(OBJS)
	rm -Rf $(OBJ_DIR)
	make -C $(LIB_PATH) clean
fclean: clean
	rm -f $(NAME)
	make -C $(LIB_PATH) fclean
re: fclean all
.PHONY: all clean fclean re