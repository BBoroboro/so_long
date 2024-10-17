# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 14:53:49 by mamoulin          #+#    #+#              #
#    Updated: 2024/03/22 16:13:48 by mamoulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./src/main.c \
		./src/control.c \
		./src/control2.c \
		./src/control3.c \
		./src/map_utils.c \
		./src/game_utils.c \
		./src/image_utils.c \
		./src/player.c \
		./src/player2.c \
		./src/free_functions.c \
		./src/free_functions2.c \
		./src/malloc_data.c

OBJ = ${SRC:.c=.o}


NAME = so_long
HEADER = so_long.h
LIBFT = ./libft/
LIBFT_MAKE = Makefile
MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
CPPFLAGS = -I$(LIBFT) -I$(MLX_DIR) -I./libft/include -I./include
RM = rm -f
AR = ar rc

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	INCLUDES = -I/usr/include
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11
else
	INCLUDES = -I/opt/X11/include
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif
 


all:		${NAME} 

.c.o:
	${CC} ${CFLAGS} ${CPPFLAGS} -c $< -o ${<:.c=.o} $(INCLUDES)

${NAME}:	${OBJ} $(MLX_LIB)
		make -C ./libft
		make -C $(MLX_DIR)
		$(CC) $(CFLAGS) $(CPPFLAGS) -L$(LIBFT) -o $(NAME) $(OBJ) -lft -lmlx $(MLX_FLAGS)

$(MLX_DIR)/libmlx_$(UNAME).a:
	make -C $(MLX_DIR)

clean:
		${RM} ${OBJ}
		make clean -C ./libft
		make clean -C $(MLX_DIR)


fclean:		clean
			${RM} ${NAME}
			make fclean -C ./libft

re:		fclean all

.PHONY: all clean fclean re
# NAME = so_long.a
# HEADER = so_long.h
# LIBFT = ./libft/
# MLX_DIR = ./mlx

# CC = cc
# CFLAGS = -Wall -Werror -Wextra -g3
# CPPFLAGS = -I$(LIBFT) -I$(MLX_DIR) -I.
# RM = rm -f
# AR = ar rc

# UNAME := $(shell uname)

# ifeq ($(UNAME), Linux)
#   INCLUDES = -I/usr/include
#   MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11
# else
#   INCLUDES = -I/opt/X11/include
#   MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
# endif

# all: $(NAME)

# .c.o:
# 	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o ${<:.c=.o} $(INCLUDES)

# $(NAME): $(OBJ) $(MLX_DIR)/libmlx_$(UNAME).a
# 	make -C $(LIBFT)
# 	$(AR) $(NAME) $(OBJ)
# 	$(CC) $(CFLAGS) $(CPPFLAGS) -L$(LIBFT) $(MLX_FLAGS) -o so_long $(OBJ) -lft


# $(MLX_DIR)/libmlx_$(UNAME).a:
# 	make -C $(MLX_DIR)

# clean:
# 	$(RM) $(OBJ)
# 	make clean -C $(LIBFT)
# 	make clean -C $(MLX_DIR)

# fclean: clean
# 	$(RM) $(NAME)
# 	rm -f libmlx_$(UNAME).a
# 	make fclean -C $(LIBFT)
# 	make fclean -C $(MLX_DIR)

# re: fclean all

# .PHONY: all clean fclean re