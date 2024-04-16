/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <tcharpen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:19:35 by tcharpen          #+#    #+#             */
/*   Updated: 2022/05/01 14:19:35 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_hero(t_window *win)
{
	int	i_map;
	int	j_map;
	int	start;

	i_map = -1;
	start = 0;
	while (win->map.map[++i_map])
	{
		j_map = -1;
		while (win->map.map[i_map][++j_map])
		{
			if (win->map.map[i_map][j_map] == 'P')
			{
				win->map.map[i_map][j_map] = '0';
				if (!start)
				{
					win->hero.x = j_map;
					win->hero.y = i_map;
					start++;
				}
			}
		}
	}
}

void	game_over(t_window *win)
{
	win->movement++;
	ft_printf("movements : %d\n", win->movement);
	ft_printf("You have been slain !\n");
	destroy_img(win);
	mlx_destroy_window(win->mlx, win->win);
	ft_free_bonus(win->map.map, win->map.nbr_line, win->mob.lst_mob, 0);
	exit(0);
}

static void	init_frame(t_window *win)
{
	win->frame = 0;
	if (win->map.nbr_line >= 15 || win->map.nbr_col >= 15)
		win->max_frame = 30;
	else if (win->map.nbr_line > 10 || win->map.nbr_col > 10)
		win->max_frame = 50;
	else
		win->max_frame = 100;
}

int	main(int argc, char **argv)
{
	t_window	win;

	if (argc != 2)
		ft_error(1);
	check_map(argv[1], &win.map);
	open_window(&win);
	init_image(&win);
	win.hero.actual_img = win.hero.down;
	put_hero(&win);
	if (win.map.nbr_m > 0)
	{
		win.mob.lst_mob = malloc(sizeof(t_lst_mob));
		if (!win.mob.lst_mob)
			ft_free_so_long(win.map.map, win.map.nbr_line, NULL, 3);
		win.mob.lst_mob->next = 0;
		put_mobs(&win, win.mob.lst_mob);
	}
	else
		win.mob.lst_mob = 0;
	init_frame(&win);
	put_str_movement(&win);
	create_window(&win);
	mlx_loop(win.mlx);
	return (0);
}
