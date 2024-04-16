/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <tcharpen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:19:49 by tcharpen          #+#    #+#             */
/*   Updated: 2022/05/01 14:19:49 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	size_map(t_map *map, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(3);
	map->nbr_line = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->nbr_line++;
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) < 0)
		ft_error(3);
	map->map = malloc(sizeof(char *) * (map->nbr_line + 1));
	if (!map->map)
		ft_error(3);
	map->map[map->nbr_line] = 0;
}

static void	read_line(int fd, char *line, int i_map, t_map *map)
{
	line = get_next_line(fd);
	if (!line)
		ft_free_so_long(map->map, i_map, NULL, 3);
	if (!ft_strchr(line, '\n'))
		map->map[i_map] = line;
	else
	{
		map->map[i_map] = malloc(sizeof(char) * ft_strlen(line));
		if (!map->map[i_map])
			ft_free_so_long(map->map, i_map, line, 3);
		ft_strlcpy(map->map[i_map], line, ft_strlen(line));
		free(line);
	}
}

void	read_map(char *file, t_map *map)
{
	int		i_map;
	char	*line;
	int		fd;

	line = NULL;
	size_map(map, file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_free_so_long(map->map, 0, NULL, 3);
	i_map = -1;
	while (++i_map < map->nbr_line)
		read_line(fd, line, i_map, map);
	line = get_next_line(fd);
	if ((close(fd) < 0) || line)
		ft_free_so_long(map->map, i_map, line, 3);
	map->nbr_col = ft_strlen(map->map[0]);
}
