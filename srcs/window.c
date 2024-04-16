/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <tcharpen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:10:45 by tcharpen          #+#    #+#             */
/*   Updated: 2022/04/22 18:10:45 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_window(int keycode, t_window *win)
{
	if (keycode == ESC)
	{
		ft_printf("Program has been closed !\n");
		mlx_destroy_window(win->mlx, win->win);
		ft_free_so_long(win->map.map, win->map.nbr_line, NULL, 0);
		exit(0);
	}
	if (keycode == UP || keycode == DOWN
		|| keycode == LEFT || keycode == RIGHT)
		game(win, keycode);
	return (0);
}

int	destroy_window(t_window *win)
{
	ft_printf("Program has been closed !\n");
	mlx_destroy_window(win->mlx, win->win);
	ft_free_so_long(win->map.map, win->map.nbr_line, NULL, 0);
	exit(0);
	return (0);
}

int	render_next_frame(t_window *win)
{
	create_window(win);
	return (0);
}

void	create_window(t_window *win)
{
	int		i_map;
	int		j_map;
	t_img	*img;

	i_map = -1;
	img = &win->hero.actual_img;
	while (win->map.map[++i_map])
	{
		j_map = -1;
		while (win->map.map[i_map][++j_map])
		{
			if (win->map.map[i_map][j_map] == '1')
				put_image(win, &win->tree, j_map * WIDTH, i_map * HEIGHT);
			else if (win->map.map[i_map][j_map] == 'C')
				put_image(win, &win->c_close, j_map * WIDTH, i_map * HEIGHT);
			else if (win->map.map[i_map][j_map] == 'E')
				put_image(win, &win->exit, j_map * WIDTH, i_map * HEIGHT);
			else if (i_map == win->hero.y && j_map == win->hero.x)
				put_image(win, img, j_map * WIDTH, i_map * HEIGHT);
			else if (win->map.map[i_map][j_map] == 'O')
				put_image(win, &win->c_open, j_map * WIDTH, i_map * HEIGHT);
			else
				put_image(win, &win->floor, j_map * WIDTH, i_map * HEIGHT);
		}
	}
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
	win->win = mlx_new_window(win->mlx, x * WIDTH, y * HEIGHT, "so_long");
	if (!win->win)
		ft_free_so_long(win->map.map, win->map.nbr_line, NULL, 3);
	mlx_hook(win->win, 17, 0, destroy_window, win);
	mlx_hook(win->win, 2, 1L << 0, key_window, win);
	mlx_loop_hook(win->mlx, render_next_frame, win);
	win->movement = 0;
}
