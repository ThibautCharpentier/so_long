/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <tcharpen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:19:57 by tcharpen          #+#    #+#             */
/*   Updated: 2022/05/03 12:19:57 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	move_vertical(t_window *win, t_lst_mob *mob)
{
	if (mob->img.img == win->mob.up.img || mob->img.img == win->mob.up2.img)
	{
		if (win->map.map[mob->y - 1][mob->x] != '0')
			mob->img.img = win->mob.down.img;
		else
		{
			win->map.map[mob->y][mob->x] = '0';
			put_image(win, &win->floor, mob->x * WIDTH, mob->y * HEIGHT);
			mob->y--;
			win->map.map[mob->y][mob->x] = 'V';
		}
	}
	else
	{
		if (win->map.map[mob->y + 1][mob->x] != '0')
			mob->img.img = win->mob.up.img;
		else
		{
			win->map.map[mob->y][mob->x] = '0';
			put_image(win, &win->floor, mob->x * WIDTH, mob->y * HEIGHT);
			mob->y++;
			win->map.map[mob->y][mob->x] = 'V';
		}
	}
	put_image(win, &mob->img, mob->x * WIDTH, mob->y * HEIGHT);
}

static void	move_horizontal(t_window *win, t_lst_mob *mob, void *img)
{
	if (img == win->mob.right.img || img == win->mob.right2.img)
	{
		if (win->map.map[mob->y][mob->x + 1] != '0')
			mob->img.img = win->mob.left.img;
		else
		{
			win->map.map[mob->y][mob->x] = '0';
			put_image(win, &win->floor, mob->x * WIDTH, mob->y * HEIGHT);
			mob->x++;
			win->map.map[mob->y][mob->x] = 'H';
		}
	}
	else
	{
		if (win->map.map[mob->y][mob->x - 1] != '0')
			mob->img.img = win->mob.right.img;
		else
		{
			win->map.map[mob->y][mob->x] = '0';
			put_image(win, &win->floor, mob->x * WIDTH, mob->y * HEIGHT);
			mob->x--;
			win->map.map[mob->y][mob->x] = 'H';
		}
	}
	put_image(win, &mob->img, mob->x * WIDTH, mob->y * HEIGHT);
}

static void	check_slain_hero(t_window *win, t_lst_mob *mob)
{
	if (mob->x == win->hero.x && mob->y == win->hero.y)
	{
		ft_printf("You have been slain !\n");
		destroy_img(win);
		mlx_destroy_window(win->mlx, win->win);
		ft_free_bonus(win->map.map, win->map.nbr_line, win->mob.lst_mob, 0);
		exit(0);
	}
}

void	move_enemy(t_window *win, t_lst_mob *mob)
{
	t_lst_mob	*tmp;

	tmp = mob;
	while (tmp->next)
	{
		if (tmp->type == 'V')
			move_vertical(win, tmp);
		else
			move_horizontal(win, tmp, tmp->img.img);
		check_slain_hero(win, tmp);
		tmp = tmp->next;
	}
}
