/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:38:56 by tcharpen          #+#    #+#             */
/*   Updated: 2022/04/29 15:38:58 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*image(t_img *img, void *mlx, char *path)
{
	return (mlx_xpm_file_to_image(mlx, path, &img->width, &img->height));
}

void	init_image(t_window *win)
{
	win->floor.img = image(&win->floor, win->mlx, FLOOR);
	win->tree.img = image(&win->tree, win->mlx, TREE);
	win->exit.img = image(&win->exit, win->mlx, HOUSE);
	win->c_open.img = image(&win->c_open, win->mlx, C_OPEN);
	win->c_close.img = image(&win->c_close, win->mlx, C_CLOSE);
	win->hero.up.img = image(&win->hero.up, win->mlx, H_UP);
	win->hero.down.img = image(&win->hero.down, win->mlx, H_DOWN);
	win->hero.left.img = image(&win->hero.left, win->mlx, H_LEFT);
	win->hero.right.img = image(&win->hero.right, win->mlx, H_RIGHT);
	if (!win->floor.img || !win->tree.img || !win->exit.img
		|| !win->c_open.img || !win->c_close.img || !win->hero.up.img
		|| !win->hero.down.img || !win->hero.left.img || !win->hero.right.img)
		ft_free_so_long(win->map.map, win->map.nbr_line, NULL, 3);
}

void	put_image(t_window *win, t_img *img, int x, int y)
{
	mlx_put_image_to_window(win->mlx, win->win, img->img, x, y);
}

void	destroy_img(t_window *win)
{
	mlx_destroy_image(win->mlx, win->floor.img);
	mlx_destroy_image(win->mlx, win->tree.img);
	mlx_destroy_image(win->mlx, win->exit.img);
	mlx_destroy_image(win->mlx, win->c_open.img);
	mlx_destroy_image(win->mlx, win->c_close.img);
	mlx_destroy_image(win->mlx, win->hero.up.img);
	mlx_destroy_image(win->mlx, win->hero.down.img);
	mlx_destroy_image(win->mlx, win->hero.left.img);
	mlx_destroy_image(win->mlx, win->hero.right.img);
}
