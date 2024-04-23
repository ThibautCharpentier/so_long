/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <tcharpen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:20:02 by tcharpen          #+#    #+#             */
/*   Updated: 2022/05/01 14:20:02 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H

# define SO_LONG_BONUS_H

# include "../libft/libft.h" // contains unistd, stdarg, stdlib
# include "../libmlx/mlx.h"
# include <fcntl.h>

# define ESC 65307 // ESC key
# define UP 122 // Z key = 122, W key = 119
# define DOWN 115 // S key = 115
# define LEFT 113 // Q key = 113, A key = 97
# define RIGHT 100 // D key = 100
# define HEIGHT 65 // images height
# define WIDTH 48 // images width
# define MAX_HEIGHT 1080 // depends on your screen
# define MAX_WIDTH 1920 // depends on your screen

# define FLOOR "./images/floor.xpm"
# define TREE "./images/tree.xpm"
# define HOUSE "./images/exit.xpm"
# define C_OPEN "./images/chest_open.xpm"
# define C_CLOSE "./images/chest_close.xpm"
# define H_UP "./images/hero/hero_up2.xpm"
# define H_DOWN "./images/hero/hero_down2.xpm"
# define H_LEFT "./images/hero/hero_left2.xpm"
# define H_RIGHT "./images/hero/hero_right2.xpm"
# define H_UP2 "./images/hero/hero_up3.xpm"
# define H_DOWN2 "./images/hero/hero_down3.xpm"
# define H_LEFT2 "./images/hero/hero_left3.xpm"
# define H_RIGHT2 "./images/hero/hero_right3.xpm"
# define M_UP "./images/mob/mob_up2.xpm"
# define M_DOWN "./images/mob/mob_down2.xpm"
# define M_LEFT "./images/mob/mob_left2.xpm"
# define M_RIGHT "./images/mob/mob_right2.xpm"
# define M_UP2 "./images/mob/mob_up3.xpm"
# define M_DOWN2 "./images/mob/mob_down3.xpm"
# define M_LEFT2 "./images/mob/mob_left3.xpm"
# define M_RIGHT2 "./images/mob/mob_right3.xpm"

/* ////////// STRUCT ////////// */

typedef struct s_map
{
	char	**map;
	int		nbr_line;
	int		nbr_col;
	int		nbr_c;
	int		nbr_e;
	int		nbr_p;
	int		nbr_m;
}				t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
	char	*path;
}				t_img;

typedef struct s_hero
{
	t_img	right;
	t_img	left;
	t_img	up;
	t_img	down;
	t_img	right2;
	t_img	left2;
	t_img	up2;
	t_img	down2;
	t_img	actual_img;
	int		x;
	int		y;
}				t_hero;

typedef struct s_lst_mob
{
	t_img				img;
	int					x;
	int					y;
	char				type;
	struct s_lst_mob	*next;
}				t_lst_mob;

typedef struct s_mob
{
	t_img		right;
	t_img		left;
	t_img		up;
	t_img		down;
	t_img		right2;
	t_img		left2;
	t_img		up2;
	t_img		down2;
	int			move;
	t_lst_mob	*lst_mob;
}				t_mob;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_img	floor;
	t_img	tree;
	t_img	exit;
	t_img	c_open;
	t_img	c_close;
	t_hero	hero;
	t_mob	mob;
	int		movement;
	int		frame;
	int		max_frame;
}				t_window;

/* ////////// FCT ////////// */

void	change_image_hero(t_hero *hero);
void	change_image_hero2(t_hero *hero);
void	change_image_mob(t_window *win, t_lst_mob *mob);
void	change_image_mob2(t_window *win, t_lst_mob *mob);
void	check_map(char *file, t_map *map);
void	ft_error(int error);
void	ft_free_so_long(char **map, int max_i_map, char *str, int error);
void	ft_free_bonus(char **map, int max_i_map, t_lst_mob *mob, int error);
void	move_enemy(t_window *win, t_lst_mob *mob);
void	move_hero(t_window *win, int keycode);
void	move_hero2(t_window *win, int keycode);
void	*image(t_img *img, void *mlx, char *path);
void	init_image(t_window *win);
void	put_image(t_window *win, t_img *img, int x, int y);
void	destroy_img(t_window *win);
void	game_over(t_window *win);
void	put_mobs(t_window *win, t_lst_mob *mob);
void	read_map(char *file, t_map *map);
void	open_window(t_window *window);
int		destroy_window(t_window *windows);
int		key_window(int keycode, t_window *windows);
void	put_str_movement(t_window *win);
void	create_window(t_window *win);
int		render_next_frame(t_window *win);

#endif
