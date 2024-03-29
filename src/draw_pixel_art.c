/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel_art.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 01:54:29 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/22 11:13:46 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_ascii_art_pixel(t_main *config, int x, int y, void *img)
{
	mlx_put_image_to_window(config->mlx, config->win, img, \
				((x + config->ascii_art_offset) * \
				(BLOCK_SIZE / PIXEL_LENGTH)), \
				(((y + (config->height / 2)) * \
				(BLOCK_SIZE / PIXEL_LENGTH))) + \
				(LOG_LENGTH * LOG_FONT_HEIGTH) + \
				(PIXEL_LENGTH * ((config->height / 2) - 1)));
	usleep(1000000 * TIME_BETWEEN_PIXEL);
}

static	int	print_ascii_get_offset(t_main *config, int length)
{
	int	length_in_pixel;
	int	total_length;

	length_in_pixel = length * 8;
	total_length = config->width * 8;
	return ((total_length - length_in_pixel) / 2);
}

void	print_ascii_art_loose(t_main *config)
{
	config->ascii_art_offset = print_ascii_get_offset(config, 5);
	print_ascii_l(config);
	print_ascii_l_shadow(config);
	print_ascii_o(config, 0);
	print_ascii_o_shadow(config, 0);
	print_ascii_o(config, 8);
	print_ascii_o_shadow(config, 8);
	print_ascii_s(config);
	print_ascii_s_shadow(config);
	print_ascii_e(config);
	print_ascii_e_shadow(config);
}

void	print_ascii_art_win(t_main *config)
{
	config->ascii_art_offset = print_ascii_get_offset(config, 3);
	print_ascii_w(config);
	print_ascii_w_shadow(config);
	print_ascii_i(config);
	print_ascii_i_shadow(config);
	print_ascii_n(config);
	print_ascii_n_shadow(config);
}
