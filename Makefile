# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocmarout <ocmarout@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 14:58:03 by ocmarout          #+#    #+#              #
#    Updated: 2021/09/20 21:14:09 by ocmarout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	SoLong.c

NAME		=	so_long

OBJS		=	${SRCS:.c=.o}

OBJS_DIR	=	./.objs/

CC			=	clang
MKDIR		=	mkdir -p

CFLAGS		=	-Wall -Wextra -Werror ${INCLUDES}

INCLUDES	=	-I includes/ -I libft/includes/ -I mlx_linux/

all:		norme ${NAME}

bonus:		all

${NAME}:	$(addprefix ${OBJS_DIR}, ${OBJS})
		make -C libft/
		make -C mlx_linux/
		$(CC) -o $@ $^ ${CFLAGS} -L./libft/ -lft -Lmlx_linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz

${OBJS_DIR}:
		${MKDIR} ${OBJS_DIR}

${OBJS_DIR}%.o:	${SRCS_DIR}%.c | ${OBJS_DIR}
		${CC} ${CFLAGS} -c $< -o ${@}

clean:
		make clean -C libft/
		rm -rf ${OBJS_DIR}

fclean: clean
		make fclean -C libft/
		rm -f ${NAME}

re:		fclean ${OBJS_DIR} all

norme:
		norminette ${SRCS}
