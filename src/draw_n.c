/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 02:05:34 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/22 10:47:33 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_ascii_n(t_main *config)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 6)
	{
		while (j < 10)
		{
			if (i < 2 || i > 3)
				print_ascii_art_pixel(config, 17 + i, 1 + j, \
												config->textures->green_pixel);
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	while (i < 4)
		print_ascii_art_pixel(config, 19, 3 + i++, \
												config->textures->green_pixel);
	i = 0;
	while (i < 4)
		print_ascii_art_pixel(config, 20, 5 + i++, \
												config->textures->green_pixel);
}

void	print_ascii_n_shadow(t_main *config)
{
	int	i;

	print_ascii_art_pixel(config, 19, 2, config->textures->dark_green_pixel);
	i = 0;
	while (i < 5)
		print_ascii_art_pixel(config, 19, 7 + i++, \
											config->textures->dark_green_pixel);
	print_ascii_art_pixel(config, 18, 11, \
											config->textures->dark_green_pixel);
	print_ascii_art_pixel(config, 20, 4, \
											config->textures->dark_green_pixel);
	i = 0;
	while (i < 10)
		print_ascii_art_pixel(config, 23, 2 + i++, \
											config->textures->dark_green_pixel);
	print_ascii_art_pixel(config, 22, 11, \
											config->textures->dark_green_pixel);
}
