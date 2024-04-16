/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <tcharpen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:31:37 by tcharpen          #+#    #+#             */
/*   Updated: 2022/04/26 19:31:37 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_to(t_window *win, t_img *img, int x, int y)
{
	put_image(win, &win->floor, win->hero.x * WIDTH, win->hero.y * HEIGHT);
	put_image(win, img, x * WIDTH, y * HEIGHT);
	win->hero.x = x;
	win->hero.y = y;
	win->movement++;
	ft_printf("movements : %d\n", win->movement);
}

static void	open_chest(t_window *win, t_img *img, int x, int y)
{
	put_image(win, &win->c_open, x * WIDTH, y * HEIGHT);
	put_image(win, img, win->hero.x * WIDTH, win->hero.y * HEIGHT);
	win->map.nbr_c--;
	win->map.map[y][x] = 'O';
	win->movement++;
	ft_printf("movements : %d\n", win->movement);
}

static t_img	move_hero(t_window *win, t_img *img, int x, int y)
{
	if (win->map.map[y][x] == '1' || win->map.map[y][x] == 'O')
		put_image(win, img, win->hero.x * WIDTH, win->hero.y * HEIGHT);
	else if (win->map.map[y][x] == 'E' && win->map.nbr_c)
		put_image(win, img, win->hero.x * WIDTH, win->hero.y * HEIGHT);
	else if (win->map.map[y][x] == 'E' && !win->map.nbr_c)
	{
		win->movement++;
		ft_printf("movements : %d\n", win->movement);
		put_image(win, &win->floor, win->hero.x * WIDTH, y * HEIGHT);
		ft_printf("You are a champion my friend !\n");
		destroy_img(win);
		mlx_destroy_window(win->mlx, win->win);
		ft_free_so_long(win->map.map, win->map.nbr_line, NULL, 0);
		exit(0);
	}
	else if (win->map.map[y][x] == '0')
		move_to(win, img, x, y);
	else if (win->map.map[y][x] == 'C')
		open_chest(win, img, x, y);
	return (*img);
}

void	game(t_window *win, int keycode)
{
	t_img	img;

	img = win->hero.actual_img;
	if (keycode == UP)
		img = move_hero(win, &win->hero.up, win->hero.x, win->hero.y - 1);
	else if (keycode == DOWN)
		img = move_hero(win, &win->hero.down, win->hero.x, win->hero.y + 1);
	else if (keycode == RIGHT)
		img = move_hero(win, &win->hero.right, win->hero.x + 1, win->hero.y);
	else if (keycode == LEFT)
		img = move_hero(win, &win->hero.left, win->hero.x - 1, win->hero.y);
	win->hero.actual_img = img;
}
