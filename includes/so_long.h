/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:59:52 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/15 22:42:01 by brda-sil         ###   ########.fr       */
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
#  define DEBUG	0
# endif

// UI
# define WIN_TITLE		"SO LONG..."
# define INFO_PADDING	74
# define BLOCK_SIZE		32
# define FPS 			60

// GAME
# define DEFAULT_PLAYER_HEALTH	5
# define DEFAULT_PLAYER_DAMAGE	1
# define DEFAULT_ENEMY_HEALTH	3
# define DEFAULT_ENEMY_DAMAGE	0.25

// KEYBOARD
	// DEFAULT
# define KEY_A	0x61
# define KEY_W	0x77
# define KEY_S	0x73
# define KEY_D	0x64

	// ARROW
# define KEY_UP		0xff52
# define KEY_RIGHT	0xff53
# define KEY_DOWN	0xff54
# define KEY_LEFT	0xff51

	// EXTRA
# define KEY_R		0x72
# define KEY_ESC	0xff1b

// OTHER
# define GOOD_POINT	"10EPCK"

/* ########################################################################## */

/* ########################################################################## */
/* STRUCT */
/* ###### */

typedef struct s_textures {
	void	*health_01;
	void	*health_02;
	void	*health_03;
	void	*health_04;
	void	*health_05;
	void	*health_06;
	void	*health_07;
	void	*health_08;
	void	*health_09;
	void	*health_10;
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
	void	*player;
	void	*enemy;
	void	*grave;
	void	*player_on_grave;
	void	*ground;
	void	*door_open;
	void	*door_close;
	void	*key;
}				t_textures;

typedef struct s_enemy {
	double	health;
	int		pos_x;
	int		pos_y;
}				t_enemy;

typedef struct s_main {
	void		*mlx;
	void		*win;
	t_textures	*textures;
	int			texture_loaded;
	int			enemy_loaded;
	int			map_loaded;
	int			map_new_loaded;
	char		saved_block;
	int			retry;
	int			is_finished;
	char		**map;
	char		**map_new;
	int			is_map_new;
	int			p_x;
	int			p_y;
	double		p_health;
	int			p_key;
	int			p_win;
	int			p_step;
	int			p_last_step;
	int			width;
	int			height;
	int			nb_player;
	int			nb_enemy;
	int			nb_door;
	int			nb_key;
	t_enemy		**enemy;
}				t_main;

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// change_wall.c
void	change_corner(t_main *config, int dir[4], int i, int j);
void	change_1(t_main *config, int dir[4], int i, int j);
void	change_3(t_main *config, int dir[4], int i, int j);

// draw_health_bar.c
void	draw_player(t_main *config, int x, int y);
void	draw_enemy(t_main *config, int x, int y);
int		get_enemy_id(t_main *config, int y, int x);

// draw_str.c
void	print_close(t_main *config);
void	print_retry(t_main *config);
void	retry_choose(t_main *config);
void	print_before_win_loose(t_main *config);

// draw.c
int		draw_map(t_main *config);
void	draw_block(t_main *config, int x, int y);
void	draw_wall_block_oriented(t_main *config, int x, int y);
void	put_image(t_main *config, void *img, int x, int y);

// free.c
void	free_texture(t_main *config, void *texture);
void	free_entry_point(t_main *config);
void	free_map(t_main *config);
void	free_map_new(t_main *config);

// free.2.c
void	free_texture_walls(t_main *config);
void	free_texture_health(t_main *config);

// game_duel.c
void	duel(t_main *config);

// game_move.c
void	move_player_loop(t_main *config, int x, int y);
void	move_player(t_main *config, int x, int y);

// game.c
int		keypress(int keycode, t_main *config);
int		keyrelease(int keycode, t_main *config);
void	open_door(t_main *config);
void	put_steps(t_main *config);

// init_enemy.c
void	init_enemy(t_main *config);
t_enemy	*init_get_enemy(int i, int j);
void	free_enemy(t_main *config);
void	init_texture_health(t_main *config);

// init.c
void	*texture_load(t_main *config, char *path);
void	init_texture(t_main *config);
void	init_main(t_main *config);
void	init_entry_point(t_main *config);
void	init_hook(t_main *config);

// map_check_2.c
int		check_minimum_point(t_main *config);
void	exit_minimum_point(int return_code);
int		check_is_wall(char block);
int		end_hook(t_main *config);
int		check_move(t_main *config, int x, int y, char next_move);

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

// so_long.c
int		move_win(t_main *config, int x, int y);

// debug.c
void	debug_print_map_without_9(t_main *config);
void	debug_print_map_with_9(t_main *config);
void	debug_print_current_block(t_main *config, int x, int y);
void	debug_print_enemy_info(t_main *config, int x, int y);
void	debug_print_player_info(t_main *config, int x, int y);

// debug.2.c
void	debug_print_keycode_press(t_main *config, int keycode);
void	debug_print_keycode_release(int keycode);
void	debug_print_inited(t_main *config);

/* ########################################################################## */

#endif
