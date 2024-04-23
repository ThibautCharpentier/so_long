# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcharpen <tcharpen@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 18:46:45 by tcharpen          #+#    #+#              #
#    Updated: 2022/04/22 18:46:45 by tcharpen         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

HDR = srcs/so_long.h
HDR_BONUS = srcs_bonus/so_long_bonus.h

SRCS = check_map.c error.c free.c main.c read_map.c \
window.c game.c image.c
SRCS_BONUS = check_map_bonus.c error_bonus.c free_bonus.c main_bonus.c \
window_bonus.c move_hero_bonus.c image_bonus.c read_map_bonus.c \
next_frame_bonus.c put_mobs_bonus.c move_enemy_bonus.c change_image_bonus.c

OBJS = ${addprefix srcs/,${SRCS:.c=.o}}
OBJS_BONUS = ${addprefix srcs_bonus/,${SRCS_BONUS:.c=.o}}

LIBMLX = libmlx

LIBFT_AR = libft/libft.a
LIBMLX_AR = ${LIBMLX}/libmlx.a

INCLUDES_HOME = -Ilibft -I/usr/include -Ilibmlx
LIBS_HOME = -Llibft -lft -Llibmlx -lmlx -L/usr/lib -lXext -lX11 -lm -lz

INCLUDES_42 = -Ilibft -I/usr/X11/include -Ilibmlx
LIBS_42 = -Llibft -lft -Llibmlx -lmlx -L/usr/X11/lib -lXext -lX11 -lm -lz

CC = gcc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c ${HDR} ${HDR_BONUS} ${LIBFT_AR} ${LIBMLX_AR} Makefile
	${CC} ${CFLAGS} -c $< -o $@ ${INCLUDES_HOME}

all: libft libmlx ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS_HOME}

bonus: libft libmlx ${NAME_BONUS}

${NAME_BONUS}: ${OBJS_BONUS}
	${CC} ${CFLAGS} -o ${NAME_BONUS} ${OBJS_BONUS} ${LIBS_HOME}

libft:
	make -C libft

libmlx:
	make -C ${LIBMLX}

clean:
	rm -f ${OBJS} ${OBJS_BONUS}
	make clean -C ${LIBMLX}
	make clean -C libft

fclean: clean
	rm -f ${NAME} ${NAME_BONUS}
	make fclean -C libft

re: fclean all

.PHONY: all bonus libmlx libft clean fclean re
