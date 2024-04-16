/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_image_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <tcharpen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:11:27 by tcharpen          #+#    #+#             */
/*   Updated: 2022/05/03 14:11:27 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	change_image_hero(t_hero *hero)
{
	if (hero->actual_img.img == hero->up.img)
		hero->actual_img = hero->up2;
	else if (hero->actual_img.img == hero->down.img)
		hero->actual_img = hero->down2;
	else if (hero->actual_img.img == hero->right.img)
		hero->actual_img = hero->right2;
	else if (hero->actual_img.img == hero->left.img)
		hero->actual_img = hero->left2;
}

void	change_image_hero2(t_hero *hero)
{
	if (hero->actual_img.img == hero->up2.img)
		hero->actual_img = hero->up;
	else if (hero->actual_img.img == hero->down2.img)
		hero->actual_img = hero->down;
	else if (hero->actual_img.img == hero->right2.img)
		hero->actual_img = hero->right;
	else if (hero->actual_img.img == hero->left2.img)
		hero->actual_img = hero->left;
}

void	change_image_mob(t_window *win, t_lst_mob *mob)
{
	t_lst_mob	*tmp;

	tmp = mob;
	while (tmp->next)
	{
		if (tmp->img.img == win->mob.up.img)
			tmp->img = win->mob.up2;
		else if (tmp->img.img == win->mob.down.img)
			tmp->img = win->mob.down2;
		else if (tmp->img.img == win->mob.left.img)
			tmp->img = win->mob.left2;
		else if (tmp->img.img == win->mob.right.img)
			tmp->img = win->mob.right2;
		tmp = tmp->next;
	}
}

void	change_image_mob2(t_window *win, t_lst_mob *mob)
{
	t_lst_mob	*tmp;

	tmp = mob;
	while (tmp->next)
	{
		if (tmp->img.img == win->mob.up2.img)
			tmp->img = win->mob.up;
		else if (tmp->img.img == win->mob.down2.img)
			tmp->img = win->mob.down;
		else if (tmp->img.img == win->mob.left2.img)
			tmp->img = win->mob.left;
		else if (tmp->img.img == win->mob.right2.img)
			tmp->img = win->mob.right;
		tmp = tmp->next;
	}
}
