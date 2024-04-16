/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <tcharpen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:32:46 by tcharpen          #+#    #+#             */
/*   Updated: 2022/04/22 18:32:46 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_error_map(int error)
{
	if (error == 4)
		ft_printf("Your map is too small.\n");
	else if (error == 5)
		ft_printf("Your map is not rectangular.\n");
	else if (error == 6)
		ft_printf("Your map is not closed by walls '1'.\n");
	else if (error == 6)
		ft_printf("Your map is not closed by walls '1'.\n");
	else if (error == 7)
	{
		ft_printf("Your map must only contain ");
		ft_printf(" these characters '1', '0', 'E', 'P' or 'C'.\n");
	}
	else
	{
		ft_printf("Your map is missing collectible(s) 'C', exit(s) 'E'");
		ft_printf(" or starting position(s) 'P'.\n");
	}
}

void	ft_error(int error)
{
	ft_printf("Error\n");
	if (error == 1)
	{
		ft_printf("The program must start with a single parameter,");
		ft_printf(" as follows : ./so_long <fichier '*.ber'>\n");
	}
	else if (error == 2)
	{
		ft_printf("The file is not valid,");
		ft_printf(" it must have the '*.ber' extension.\n");
	}
	else if (error == 3)
		ft_printf("Problem encountered while launching the process.\n");
	else if (error == 9)
		ft_printf("Your map is to large !\n");
	else
		ft_error_map(error);
	exit(1);
}
