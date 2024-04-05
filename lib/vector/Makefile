# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 14:28:17 by evocatur          #+#    #+#              #
#    Updated: 2024/04/05 14:49:57 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = vector.a

SRCS = vector.c vector_set.c string_to_vector.c vector_dir.c

OBJS = ${SRCS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

LINKS += -Llib/libft/ -lft 

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o} $(LINKS) 

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS} ${OBJSBONUS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all
