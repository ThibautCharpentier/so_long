/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_frame_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <tcharpen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:15:33 by tcharpen          #+#    #+#             */
/*   Updated: 2022/05/02 17:15:33 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	render_next_frame(t_window *win)
{
	win->frame++;
	if (win->frame >= win->max_frame)
	{
		change_image_hero(&win->hero);
		if (win->mob.lst_mob)
			change_image_mob(win, win->mob.lst_mob);
		if (win->frame >= win->max_frame * 2)
			win->frame = 0;
	}
	else if (win->frame < win->max_frame)
	{
		change_image_hero2(&win->hero);
		if (win->mob.lst_mob)
			change_image_mob2(win, win->mob.lst_mob);
	}
	create_window(win);
	return (0);
}

static void	put_the_right_image(t_window *win, int i_map, int j_map)
{
	if (win->map.map[i_map][j_map] == '1')
		put_image(win, &win->tree, j_map * WIDTH, i_map * HEIGHT);
	else if (win->map.map[i_map][j_map] == 'C')
		put_image(win, &win->c_close, j_map * WIDTH, i_map * HEIGHT);
	else if (win->map.map[i_map][j_map] == 'E')
		put_image(win, &win->exit, j_map * WIDTH, i_map * HEIGHT);
	else if (i_map == win->hero.y && j_map == win->hero.x)
		put_image(win, &win->hero.actual_img, j_map * WIDTH, i_map * HEIGHT);
	else if (win->map.map[i_map][j_map] == 'O')
		put_image(win, &win->c_open, j_map * WIDTH, i_map * HEIGHT);
	else
		put_image(win, &win->floor, j_map * WIDTH, i_map * HEIGHT);
}

static void	put_the_enemy(t_window *win, int i_map, int j_map, t_lst_mob *mob)
{
	t_lst_mob	*tmp;

	tmp = mob;
	while (tmp->next)
	{
		if (tmp->x == j_map && tmp->y == i_map)
			break ;
		tmp = tmp->next;
	}
	put_image(win, &tmp->img, j_map * WIDTH, i_map * HEIGHT);
}

void	create_window(t_window *win)
{
	int			i_map;
	int			j_map;

	i_map = -1;
	while (win->map.map[++i_map])
	{
		j_map = -1;
		while (win->map.map[i_map][++j_map])
		{
			if ((win->map.map[i_map][j_map] == 'V'
				|| win->map.map[i_map][j_map] == 'H') && win->mob.lst_mob)
				put_the_enemy(win, i_map, j_map, win->mob.lst_mob);
			else if (i_map == 0 && j_map == 0)
			{
				if (win->frame % 10 == 0)
					put_str_movement(win);
				j_map += 2;
			}
			else
				put_the_right_image(win, i_map, j_map);
		}
	}
}
