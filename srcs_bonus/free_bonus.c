/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <tcharpen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:18:40 by tcharpen          #+#    #+#             */
/*   Updated: 2022/05/01 14:18:40 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	ft_free_bonus(char **map, int max_i_map, t_lst_mob *mob, int error)
{
	int			i_map;
	t_lst_mob	*tmp;

	i_map = -1;
	while (++i_map < max_i_map)
		free(map[i_map]);
	free(map);
	tmp = mob;
	while (mob)
	{
		tmp = mob->next;
		free(mob);
		mob = tmp;
	}
	if (error)
		ft_error(error);
}
