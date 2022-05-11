/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:59:52 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/12 01:18:51 by brda-sil         ###   ########.fr       */
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

// STRUCTURES
typedef struct s_img {
	void	*img;
	char	*addr;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}				t_img;

typedef struct s_textures {
	t_img	*character;
	t_img	*wall;
}				t_textures;

typedef struct s_main {
	void		*mlx;
	void		*win;
}				t_main;

// init.c
t_img		*texture_load(t_main *config, char *path);
void		init_texture(t_main *config, t_textures *textures);
void		init_main(t_main *config, int height, int width, char *title);
void		init_entry_point(t_main *config, t_textures *textures);

// free.c
void		free_texture(t_main *config, t_img *texture);
void		free_entry_point(t_main *config, t_textures *textures);

#endif
