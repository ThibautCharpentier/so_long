/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <tcharpen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:20:30 by tcharpen          #+#    #+#             */
/*   Updated: 2022/05/01 14:20:30 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_window(int keycode, t_window *win)
{
	if (keycode == ESC)
	{
		ft_printf("Program has been closed !\n");
		mlx_destroy_window(win->mlx, win->win);
		ft_free_bonus(win->map.map, win->map.nbr_line, win->mob.lst_mob, 0);
		exit(0);
	}
	if (keycode == UP || keycode == DOWN
		|| keycode == LEFT || keycode == RIGHT)
	{
		win->mob.move = 0;
		if (win->frame < 100)
			move_hero(win, keycode);
		else
			move_hero2(win, keycode);
		if (win->mob.move && win->map.nbr_m)
			move_enemy(win, win->mob.lst_mob);
	}
	return (0);
}

void	put_str_movement(t_window *win)
{
	char	*movements;

	movements = ft_itoa(win->movement);
	mlx_put_image_to_window(win->mlx, win->win, win->tree.img, 0, 0);
	mlx_string_put(win->mlx, win->win, 5, 15, 0xFFFFFFFF, "movements : ");
	mlx_string_put(win->mlx, win->win, 75, 16, 0xFFFFFFFF, movements);
	mlx_put_image_to_window(win->mlx, win->win, win->tree.img, WIDTH, 0);
	mlx_string_put(win->mlx, win->win, 5, 15, 0xFFFFFFFF, "movements : ");
	mlx_string_put(win->mlx, win->win, 75, 16, 0xFFFFFFFF, movements);
	put_image(win, &win->tree, 2 * WIDTH, 0 * HEIGHT);
	mlx_string_put(win->mlx, win->win, 5, 15, 0xFFFFFFFF, "movements : ");
	mlx_string_put(win->mlx, win->win, 75, 16, 0xFFFFFFFF, movements);
	free(movements);
}

int	destroy_window(t_window *win)
{
	ft_printf("Program has been closed !\n");
	mlx_destroy_window(win->mlx, win->win);
	ft_free_bonus(win->map.map, win->map.nbr_line, win->mob.lst_mob, 0);
	exit(0);
	return (0);
}

void	open_window(t_window *win)
{
	int	x;
	int	y;

	x = win->map.nbr_col;
	y = win->map.nbr_line;
	if (x * WIDTH > MAX_WIDTH || y * HEIGHT > MAX_HEIGHT)
		ft_free_so_long(win->map.map, win->map.nbr_line, NULL, 9);
	win->mlx = mlx_init();
	if (!win->mlx)
		ft_free_so_long(win->map.map, win->map.nbr_line, NULL, 3);
	win->win = mlx_new_window(win->mlx, x * WIDTH, y * HEIGHT, "so_long_b");
	if (!win->win)
		ft_free_so_long(win->map.map, win->map.nbr_line, NULL, 3);
	mlx_hook(win->win, 17, 0, destroy_window, win);
	mlx_hook(win->win, 2, 1L << 0, key_window, win);
	mlx_loop_hook(win->mlx, render_next_frame, win);
	win->movement = 0;
}
