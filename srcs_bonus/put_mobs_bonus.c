/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_mobs_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <tcharpen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:18:56 by tcharpen          #+#    #+#             */
/*   Updated: 2022/05/02 16:18:56 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_mob(t_lst_mob *mob, int i_map, int j_map, t_window *win)
{
	if (win->map.map[i_map][j_map] == 'V')
	{
		mob->img.img = win->mob.down.img;
		mob->x = j_map;
		mob->y = i_map;
		mob->type = 'V';
		return (1);
	}
	else if (win->map.map[i_map][j_map] == 'H')
	{
		mob->img.img = win->mob.left.img;
		mob->x = j_map;
		mob->y = i_map;
		mob->type = 'H';
		return (1);
	}
	return (0);
}

void	put_mobs(t_window *win, t_lst_mob *mob)
{
	int			i_map;
	int			j_map;
	t_lst_mob	*tmp;
	t_lst_mob	*new;

	i_map = -1;
	j_map = -1;
	tmp = mob;
	while (win->map.map[++i_map])
	{
		j_map = -1;
		while (win->map.map[i_map][++j_map])
		{
			if (check_mob(tmp, i_map, j_map, win))
			{
				new = malloc(sizeof(t_lst_mob));
				if (!new)
					ft_free_bonus(win->map.map, win->map.nbr_line, mob, 3);
				tmp->next = new;
				tmp = tmp->next;
				tmp->next = 0;
			}
		}
	}
}
