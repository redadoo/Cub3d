# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 14:28:17 by evocatur          #+#    #+#              #
#    Updated: 2024/04/29 00:22:19 by edoardo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = vector.a

SRCS = vector_range.c vector_set.c string_to_vector.c vector_normalize.c vector_compare.c vector_dir.c vector_print.c vector_math.c

OBJS = ${SRCS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

LINKS = -Llib/libft/ -lft -lm

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o} $(LINKS) 

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all
