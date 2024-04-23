/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharpen <tcharpen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:55:56 by tcharpen          #+#    #+#             */
/*   Updated: 2022/03/30 14:55:56 by tcharpen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

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
# define H_UP "./images/hero/hero_up1.xpm"
# define H_DOWN "./images/hero/hero_down1.xpm"
# define H_LEFT "./images/hero/hero_left1.xpm"
# define H_RIGHT "./images/hero/hero_right1.xpm"

/* ////////// STRUCT ////////// */

typedef struct s_map
{
	char	**map;
	int		nbr_line;
	int		nbr_col;
	int		nbr_c;
	int		nbr_e;
	int		nbr_p;
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
	t_img	actual_img;
	int		x;
	int		y;
}				t_hero;

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
	int		movement;
}				t_window;

/* ////////// FCT ////////// */

void	check_map(char *file, t_map *map);
void	ft_error(int error);
void	ft_free_so_long(char **map, int max_i_map, char *str, int error);
void	game(t_window *win, int keycode);
void	*image(t_img *img, void *mlx, char *path);
void	init_image(t_window *win);
void	put_image(t_window *win, t_img *img, int x, int y);
void	destroy_img(t_window *win);
void	read_map(char *file, t_map *map);
void	open_window(t_window *window);
int		destroy_window(t_window *windows);
int		key_window(int keycode, t_window *windows);
void	create_window(t_window *win);
int		render_next_frame(t_window *win);

#endif
