/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:59:52 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/12 05:00:55 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>

# define WIN_HEIGHT 640
# define WIN_WIDTH 320
# define WIN_TITLE "SO LONG..."
# define BLOCK_SIZE 32
# define GOOD_POINT "10EPC"

// STRUCTURES
typedef struct s_textures {
	void	*character;
	void	*wall;
	void	*ground;
	void	*door_open;
	void	*door_close;
}				t_textures;

typedef struct s_main {
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	int		nb_wall;
	int		nb_void;
	int		nb_player;
	int		nb_door;
	int		nb_coin;
}				t_main;

// init.c
void	*texture_load(t_main *config, char *path);
void	init_texture(t_main *config, t_textures *textures);
void	init_main(t_main *config, int height, int width, char *title);
void	init_entry_point(t_main *config, t_textures *textures);

// free.c
void	free_texture(t_main *config, void *texture);
void	free_entry_point(t_main *config, t_textures *textures);

// parse.c
int		check_ext(char *file_name);
void	parse_map(t_main *config, char *file_name);
char	*get_all_file(char *file_name);

// check_map.c
void	check_map(t_main *config, t_textures *textures);

#endif
