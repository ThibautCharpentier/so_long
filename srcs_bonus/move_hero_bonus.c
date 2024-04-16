/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <tcharpen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:20:04 by tcharpen          #+#    #+#             */
/*   Updated: 2022/05/03 12:20:04 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	move_to(t_window *win, t_img *img, int x, int y)
{
	put_image(win, &win->floor, win->hero.x * WIDTH, win->hero.y * HEIGHT);
	put_image(win, img, x * WIDTH, y * HEIGHT);
	win->hero.x = x;
	win->hero.y = y;
	win->movement++;
	ft_printf("movements : %d\n", win->movement);
	put_str_movement(win);
	win->mob.move = 1;
}

static void	open_chest(t_window *win, t_img *img, int x, int y)
{
	put_image(win, &win->c_open, x * WIDTH, y * HEIGHT);
	put_image(win, img, win->hero.x * WIDTH, win->hero.y * HEIGHT);
	win->map.nbr_c--;
	win->map.map[y][x] = 'O';
	win->movement++;
	ft_printf("movements : %d\n", win->movement);
	put_str_movement(win);
	win->mob.move = 1;
}

static t_img	move(t_window *win, t_img *img, int x, int y)
{
	if (win->map.map[y][x] == '1' || win->map.map[y][x] == 'O')
		put_image(win, img, win->hero.x * WIDTH, win->hero.y * HEIGHT);
	else if (win->map.map[y][x] == 'E' && win->map.nbr_c)
		put_image(win, img, win->hero.x * WIDTH, win->hero.y * HEIGHT);
	else if (win->map.map[y][x] == 'E' && !win->map.nbr_c)
	{
		win->movement++;
		ft_printf("movements : %d\n", win->movement);
		put_str_movement(win);
		put_image(win, &win->floor, win->hero.x * WIDTH, y * HEIGHT);
		ft_printf("You are a champion my friend !\n");
		destroy_img(win);
		mlx_destroy_window(win->mlx, win->win);
		ft_free_bonus(win->map.map, win->map.nbr_line, win->mob.lst_mob, 0);
		exit(0);
	}
	else if (win->map.map[y][x] == '0')
		move_to(win, img, x, y);
	else if (win->map.map[y][x] == 'C')
		open_chest(win, img, x, y);
	else if (win->map.map[y][x] == 'V' || win->map.map[y][x] == 'H')
		game_over(win);
	return (*img);
}

void	move_hero(t_window *win, int keycode)
{
	t_img	img;

	img = win->hero.actual_img;
	if (keycode == UP)
		img = move(win, &win->hero.up, win->hero.x, win->hero.y - 1);
	else if (keycode == DOWN)
		img = move(win, &win->hero.down, win->hero.x, win->hero.y + 1);
	else if (keycode == RIGHT)
		img = move(win, &win->hero.right, win->hero.x + 1, win->hero.y);
	else if (keycode == LEFT)
		img = move(win, &win->hero.left, win->hero.x - 1, win->hero.y);
	win->hero.actual_img = img;
}

void	move_hero2(t_window *win, int keycode)
{
	t_img	img;

	img = win->hero.actual_img;
	if (keycode == UP)
		img = move(win, &win->hero.up2, win->hero.x, win->hero.y - 1);
	else if (keycode == DOWN)
		img = move(win, &win->hero.down2, win->hero.x, win->hero.y + 1);
	else if (keycode == RIGHT)
		img = move(win, &win->hero.right2, win->hero.x + 1, win->hero.y);
	else if (keycode == LEFT)
		img = move(win, &win->hero.left2, win->hero.x - 1, win->hero.y);
	win->hero.actual_img = img;
}
