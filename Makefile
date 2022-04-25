# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 12:48:02 by ydumaine          #+#    #+#              #
#    Updated: 2022/04/24 18:37:55 by ydumaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_C = client.c\

SRCS_S = server.c\

BIBL = srcs/libft.a srcs/libftprintf.a\

OBJS_C = ${SRCS_C:.c=.o}

OBJS_S = ${SRCS_S:.c=.o}

SERVER = server

CLIENT = client

HEADER = -I include

CC = cc

LINK = cc -o

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g

.c.o: 
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${HEADER}

${SERVER}:	${OBJS_S}
			${LINK} ${SERVER} ${OBJS_S} ${BIBL}

${CLIENT}:	${OBJS_C}
			${LINK} ${CLIENT} ${OBJS_C} ${BIBL}

all:		${SERVER} ${CLIENT}

clean:
			${RM} ${OBJS_S} ${OBJS_C}

fclean:     clean
			${RM} ${SERVER} ${CLIENT}

re:			fclean all

.PHONY:		all clean fclean re bonus
