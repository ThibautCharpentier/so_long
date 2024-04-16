/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <tcharpen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:19:23 by tcharpen          #+#    #+#             */
/*   Updated: 2022/05/01 14:19:23 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*image(t_img *img, void *mlx, char *path)
{
	return (mlx_xpm_file_to_image(mlx, path, &img->width, &img->height));
}

static void	init_image_mob(t_window *win)
{
	win->mob.up.img = image(&win->mob.up, win->mlx, M_UP);
	win->mob.down.img = image(&win->mob.down, win->mlx, M_DOWN);
	win->mob.left.img = image(&win->mob.left, win->mlx, M_LEFT);
	win->mob.right.img = image(&win->mob.right, win->mlx, M_RIGHT);
	win->mob.up2.img = image(&win->mob.up2, win->mlx, M_UP2);
	win->mob.down2.img = image(&win->mob.down2, win->mlx, M_DOWN2);
	win->mob.left2.img = image(&win->mob.left2, win->mlx, M_LEFT2);
	win->mob.right2.img = image(&win->mob.right2, win->mlx, M_RIGHT2);
	if (!win->mob.up.img || !win->mob.down.img || !win->mob.left.img
		|| !win->mob.right.img || !win->mob.up2.img || !win->mob.down2.img
		|| !win->mob.left2.img || !win->mob.right2.img)
		ft_free_so_long(win->map.map, win->map.nbr_line, NULL, 3);
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
	win->hero.up2.img = image(&win->hero.up2, win->mlx, H_UP2);
	win->hero.down2.img = image(&win->hero.down2, win->mlx, H_DOWN2);
	win->hero.left2.img = image(&win->hero.left2, win->mlx, H_LEFT2);
	win->hero.right2.img = image(&win->hero.right2, win->mlx, H_RIGHT2);
	init_image_mob(win);
	if (!win->floor.img || !win->tree.img || !win->exit.img
		|| !win->c_open.img || !win->c_close.img || !win->hero.up.img
		|| !win->hero.down.img || !win->hero.left.img || !win->hero.right.img
		|| !win->hero.down2.img || !win->hero.left2.img
		|| !win->hero.right2.img || !win->hero.up2.img)
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
	mlx_destroy_image(win->mlx, win->hero.up2.img);
	mlx_destroy_image(win->mlx, win->hero.down2.img);
	mlx_destroy_image(win->mlx, win->hero.left2.img);
	mlx_destroy_image(win->mlx, win->hero.right2.img);
	mlx_destroy_image(win->mlx, win->mob.up.img);
	mlx_destroy_image(win->mlx, win->mob.down.img);
	mlx_destroy_image(win->mlx, win->mob.left.img);
	mlx_destroy_image(win->mlx, win->mob.right.img);
	mlx_destroy_image(win->mlx, win->mob.up2.img);
	mlx_destroy_image(win->mlx, win->mob.down2.img);
	mlx_destroy_image(win->mlx, win->mob.left2.img);
	mlx_destroy_image(win->mlx, win->mob.right2.img);
}
