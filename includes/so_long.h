/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:59:52 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/14 05:25:17 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>

/* ########################################################################## */

/* ########################################################################## */
/* CONFIG */
/* ###### */

# ifndef DEBUG
#  define DEBUG	1
# endif
# define WIN_TITLE "SO LONG..."
# define BLOCK_SIZE 32
# define GOOD_POINT "10EPC"

# define KEY_W		0x77
# define KEY_UP		0xff52
# define KEY_A		0x61
# define KEY_RIGHT	0xff53
# define KEY_S		0x73
# define KEY_DOWN	0xff54
# define KEY_D		0x64
# define KEY_LEFT	0xff51
# define KEY_ESC	0xff1b

/* ########################################################################## */

/* ########################################################################## */
/* STRUCT */
/* ###### */

typedef struct s_textures {
	void	*player;
	void	*wall_0;
	void	*wall_1_n;
	void	*wall_1_s;
	void	*wall_1_e;
	void	*wall_1_w;
	void	*wall_2_h;
	void	*wall_2_v;
	void	*wall_2_ur;
	void	*wall_2_ul;
	void	*wall_2_ll;
	void	*wall_2_lr;
	void	*wall_3_n;
	void	*wall_3_s;
	void	*wall_3_e;
	void	*wall_3_w;
	void	*wall_4;
	void	*ground;
	void	*door_open;
	void	*door_close;
	void	*key;
}				t_textures;

typedef struct s_main {
	void		*mlx;
	void		*win;
	t_textures	*textures;
	int			texture_loaded;
	char		**map;
	char		**map_new;
	int			p_x;
	int			p_y;
	int			p_key;
	int			p_win;
	int			width;
	int			height;
	int			nb_player;
	int			nb_door;
	int			nb_key;
}				t_main;

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// change_wall.c
void	change_corner(t_main *config, int dir[4], int i, int j);
void	change_1(t_main *config, int dir[4], int i, int j);
void	change_3(t_main *config, int dir[4], int i, int j);

// draw.c
int		draw_map(t_main *config);
void	draw_block(t_main *config, int x, int y);
void	draw_wall_block_oriented(t_main *config, int x, int y);
void	put_image(t_main *config, void *img, int x, int y);

// free.c
void	free_texture(t_main *config, void *texture);
void	free_entry_point(t_main *config);
int		free_hook(t_main *config);
void	free_map(t_main *config);
void	free_map_new(t_main *config);

// game.c
void	game_entry(t_main *config);
int		keypress(int keycode, t_main *config);
void	move_player(t_main *config, int x, int y);
int		check_move(t_main *config, char next_move);
void	open_door(t_main *config);

// init.c
void	*texture_load(t_main *config, char *path);
void	init_texture(t_main *config);
void	init_main(t_main *config, char *title);
void	init_entry_point(t_main *config);
void	init_hook(t_main *config);

// map_check_2.c
int		check_minimum_point(t_main *config);
void	exit_minimum_point(int return_code);
int		check_is_wall(char block);

// map_check.c
void	check_map(t_main *config);
int		check_surrounded(t_main *config);
int		check_wrong_point(t_main *config);
void	count_point(t_main *config, char point, int x, int y);
int		check_width(t_main *config);

// parse_wall.c
void	parse_wall(t_main *config);
void	check_wall_nearby(t_main *config, int i, int j);
void	get_direction(t_main *config, int dir[4], int i, int j);
void	parse_init_new_map(t_main *config);
int		parse_init_place_9(t_main *config, int i, int j);

// parse.c
int		check_ext(char *file_name);
void	parse_map(t_main *config, char *file_name);
char	*get_all_file(char *file_name);

/* ########################################################################## */

#endif
