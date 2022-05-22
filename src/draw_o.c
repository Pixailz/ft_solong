/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:38:18 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/22 11:09:52 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	print_ascii_o_end(t_main *config, int offset)
{
	int	i;
	int	j;

	i = 0;
	while (i < 8)
		print_ascii_art_pixel(config, 13 + offset, i++ + 2, \
												config->textures->red_pixel);
	i = 0;
	while (i < 6)
		print_ascii_art_pixel(config, 14 + offset, i++ + 3, \
												config->textures->red_pixel);
	i = 0;
	j = 0;
	while (i < 2)
	{
		while (j < 10)
		{
			if (j < 3 || j > 6)
				print_ascii_art_pixel(config, 11 + offset + i, j + 1, \
											config->textures->red_pixel);
			j++;
		}
		j = 0;
		i++;
	}
}

void	print_ascii_o(t_main *config, int offset)
{
	int	i;

	i = 0;
	while (i < 6)
		print_ascii_art_pixel(config, 9 + offset, i++ + 3, \
												config->textures->red_pixel);
	i = 0;
	while (i < 8)
		print_ascii_art_pixel(config, 10 + offset, i++ + 2, \
												config->textures->red_pixel);
	print_ascii_o_end(config, offset);
}

void	print_ascii_o_shadow(t_main *config, int offset)
{
	int	i;

	i = 0;
	while (i < 4)
		print_ascii_art_pixel(config, 11 + offset, i++ + 4, \
											config->textures->dark_red_pixel);
	print_ascii_art_pixel(config, 12 + offset, 4, \
											config->textures->dark_red_pixel);
	i = 0;
	while (i < 6)
		print_ascii_art_pixel(config, 15 + offset, i++ + 4, \
											config->textures->dark_red_pixel);
	print_ascii_art_pixel(config, 14 + offset, 10, \
											config->textures->dark_red_pixel);
	print_ascii_art_pixel(config, 14 + offset, 9, \
											config->textures->dark_red_pixel);
	print_ascii_art_pixel(config, 13 + offset, 10, \
											config->textures->dark_red_pixel);
	print_ascii_art_pixel(config, 13 + offset, 11, \
											config->textures->dark_red_pixel);
	print_ascii_art_pixel(config, 12 + offset, 11, \
											config->textures->dark_red_pixel);
}
