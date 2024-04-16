/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <tcharpen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:50:11 by tcharpen          #+#    #+#             */
/*   Updated: 2022/04/22 18:50:11 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_name_file(char *file)
{
	int	i_file;

	if (ft_strlen(file) <= 4)
		return (0);
	i_file = -1;
	while (file[++i_file])
	{
		if (file[i_file] == '.' && ft_strlen(file + i_file) == 4)
		{
			if (file[i_file + 1] == 'b' && file[i_file + 2] == 'e'
				&& file[i_file + 3] == 'r')
				return (1);
		}
	}
	return (0);
}

static void	map_is_closed(t_map *map)
{
	int	i_map;
	int	j_map;

	j_map = -1;
	while (map->map[0][++j_map])
	{
		if ((map->map[0][j_map] != '1') ||
			(map->map[map->nbr_line - 1][j_map] != '1'))
			ft_free_so_long(map->map, map->nbr_line, NULL, 6);
	}
	i_map = -1;
	while (map->map[++i_map])
	{
		if ((map->map[i_map][0] != '1') ||
			(map->map[i_map][map->nbr_col - 1] != '1'))
			ft_free_so_long(map->map, map->nbr_line, NULL, 6);
	}
}

static void	map_contains_elements(t_map *map)
{
	int	i_map;
	int	j_map;

	i_map = -1;
	while (map->map[++i_map])
	{
		j_map = -1;
		while (map->map[i_map][++j_map])
		{
			if (map->map[i_map][j_map] == 'E')
				map->nbr_e++;
			else if (map->map[i_map][j_map] == 'C')
				map->nbr_c++;
			else if (map->map[i_map][j_map] == 'P')
				map->nbr_p++;
			else if (map->map[i_map][j_map] == '0' ||
				map->map[i_map][j_map] == '1')
				continue ;
			else
				ft_free_so_long(map->map, map->nbr_line, NULL, 7);
		}
	}
	if (!map->nbr_e || !map->nbr_c || !map->nbr_p)
		ft_free_so_long(map->map, map->nbr_line, NULL, 8);
}

void	check_map(char *file, t_map *map)
{
	int	i_map;

	if (!check_name_file(file))
		ft_error(2);
	read_map(file, map);
	map->nbr_c = 0;
	map->nbr_e = 0;
	map->nbr_p = 0;
	map_contains_elements(map);
	if (map->nbr_line < 3 || map->nbr_col < 3)
		ft_free_so_long(map->map, map->nbr_line, NULL, 4);
	i_map = -1;
	while (map->map[++i_map])
	{
		if (ft_strlen(map->map[i_map]) != (size_t) map->nbr_col)
			ft_free_so_long(map->map, map->nbr_line, NULL, 5);
	}
	map_is_closed(map);
}
