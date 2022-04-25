# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 12:48:02 by ydumaine          #+#    #+#              #
#    Updated: 2022/04/25 21:36:28 by ydumaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_C = client.c\

SRCS_S = server.c\

SRCS_BC = bonus/client_bonus.c

SRCS_BS = bonus/server_bonus.c

BIBL = srcs/libft.a srcs/libftprintf.a\

OBJS_C = ${SRCS_C:.c=.o}

OBJS_S = ${SRCS_S:.c=.o}

OBJS_BC = ${SRCS_BC:.c=.o}

OBJS_BS = ${SRCS_BS:.c=.o}

SERVER = server

CLIENT = client

B_SERVER = server_bonus

B_CLIENT = client_bonus

HEADER = -I include

CC = cc

LINK = cc -o

RM = rm -f

CFLAGS = -Wall -Wextra -Werror 

.c.o: 
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${HEADER}

all:		${SERVER} ${CLIENT}

${SERVER}:	${OBJS_S}
			${LINK} ${SERVER} ${OBJS_S} ${BIBL}

${CLIENT}:	${OBJS_C}
			${LINK} ${CLIENT} ${OBJS_C} ${BIBL}

${B_SERVER}:	${OBJS_BS}
				${LINK} ${B_SERVER} ${OBJS_BS} ${BIBL}

${B_CLIENT}:	${OBJS_BC}
				${LINK} ${B_CLIENT} ${OBJS_BC} ${BIBL}


bonus:		${B_SERVER} ${B_CLIENT}

clean:
			${RM} ${OBJS_S} ${OBJS_C} ${OBJS_BS} ${OBJS_BC}

fclean:     clean
			${RM} ${SERVER} ${CLIENT} ${B_SERVER} ${B_CLIENT}

re:			fclean all

.PHONY:		all clean fclean re bonus
