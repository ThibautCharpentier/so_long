/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <tcharpen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:47:42 by tcharpen          #+#    #+#             */
/*   Updated: 2022/04/23 14:47:42 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_so_long(char **map, int max_i_map, char *str, int error)
{
	int	i_map;

	i_map = -1;
	if (str)
		free(str);
	while (++i_map < max_i_map)
		free(map[i_map]);
	free(map);
	if (error)
		ft_error(error);
}
