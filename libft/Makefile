# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 17:05:33 by mamoulin          #+#    #+#              #
#    Updated: 2024/02/06 15:31:30 by mamoulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_isalpha.c \
       ft_isdigit.c \
       ft_isalnum.c \
       ft_isascii.c \
       ft_isprint.c \
       ft_strlen.c \
       ft_toupper.c \
       ft_tolower.c \
       ft_strncmp.c \
       ft_strcmp.c \
       ft_atoi.c \
       ft_strchr.c \
       ft_strrchr.c \
       ft_strnstr.c \
       ft_strdup.c \
       ft_memset.c \
       ft_bzero.c \
       ft_memcpy.c \
       ft_memmove.c \
       ft_strlcpy.c \
       ft_strlcat.c \
       ft_memchr.c \
       ft_memcmp.c \
       ft_calloc.c \
       ft_substr.c \
       ft_strjoin.c \
       ft_strtrim.c \
       ft_split.c \
       ft_strmapi.c \
       ft_striteri.c \
       ft_putchar_fd.c \
       ft_putstr_fd.c \
       ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_itoa.c \
       ft_free_tab.c	\
       get_next_line.c \
       get_next_line_utils.c

OBJ = ${SRC:.c=.o}

SRCSBONUS = ft_lstnew.c \
	    ft_lstadd_front.c \
	    ft_lstsize.c \
	    ft_lstlast.c \
	    ft_lstadd_back.c \
	    ft_lstdelone.c \
	    ft_lstclear.c \
	    ft_lstiter.c \
	    ft_lstmap.c


OBJSBONUS = ${SRCSBONUS:.c=.o} 

NAME = libft.a
HEADER = libft.h
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
OPTION = -I ${HEADER}
RM = rm -f
AR = ar rc
RN = ranlib

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJ}
			${AR} ${NAME} ${OBJ}
			${RN} ${NAME}

bonus:		${OBJSBONUS}
			${AR} ${NAME} ${OBJSBONUS}
			${RN} ${NAME}

all:		${NAME}

clean:
	${RM} ${OBJ} ${OBJSBONUS}

fclean:		clean
			${RM} ${NAME}

re:		fclean all

so:
	$(CC) -fPIC $(CFLAGS) $(SRC) $(SRCSBONUS)
	gcc -shared -o libft.so $(OBJ) ${OBJSBONUS}

.PHONY:	all bonus clean fclean re
