/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_e.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:51:02 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/22 10:55:14 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	print_ascii_e_end(t_main *config)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 10)
		{
			if (j < 2 || (j > 3 && j < 6) || j > 7)
				print_ascii_art_pixel(config, 35 + i, j + 1, \
												config->textures->red_pixel);
			j++;
		}
		j = 0;
		i++;
	}
}

void	print_ascii_e(t_main *config)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 2)
	{
		while (j < 10)
		{
			print_ascii_art_pixel(config, 33 + i, j++ + 1, \
												config->textures->red_pixel);
		}
		j = 0;
		i++;
	}
	print_ascii_e_end(config);
}

void	print_ascii_e_shadow(t_main *config)
{
	int	i;

	i = 0;
	while (i < 5)
		print_ascii_art_pixel(config, 35 + i++, 3, \
											config->textures->dark_red_pixel);
	print_ascii_art_pixel(config, 39, 2, \
											config->textures->dark_red_pixel);
	print_ascii_art_pixel(config, 35, 4, config->textures->dark_red_pixel);
	i = 0;
	while (i < 5)
		print_ascii_art_pixel(config, 35 + i++, 7, \
											config->textures->dark_red_pixel);
	print_ascii_art_pixel(config, 39, 6, config->textures->dark_red_pixel);
	print_ascii_art_pixel(config, 35, 8, config->textures->dark_red_pixel);
	i = 0;
	while (i < 6)
		print_ascii_art_pixel(config, 34 + i++, 11, \
											config->textures->dark_red_pixel);
	print_ascii_art_pixel(config, 39, 10, config->textures->dark_red_pixel);
}
