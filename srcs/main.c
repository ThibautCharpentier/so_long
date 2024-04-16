/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <tcharpen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:06:49 by tcharpen          #+#    #+#             */
/*   Updated: 2022/03/30 15:06:49 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_hero(t_window *win)
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
			if (win->map.map[i_map][j_map] == 'P')
			{
				win->map.map[i_map][j_map] = '0';
				if (img)
				{
					put_image(win, img, j_map * WIDTH, i_map * HEIGHT);
					win->hero.x = j_map;
					win->hero.y = i_map;
					img = NULL;
				}
			}
		}
	}
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
	create_window(&win);
	put_hero(&win);
	mlx_loop(win.mlx);
	return (0);
}
