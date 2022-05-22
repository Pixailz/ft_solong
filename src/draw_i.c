/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:53:57 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/22 10:46:32 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_ascii_i(t_main *config)
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
			{
				if (j < 2 || j > 7)
					print_ascii_art_pixel(config, 9 + i, 1 + j, \
												config->textures->green_pixel);
			}
			else
				print_ascii_art_pixel(config, 9 + i, 1 + j, \
												config->textures->green_pixel);
			j++;
		}
		j = 0;
		i++;
	}
}

void	print_ascii_i_shadow(t_main *config)
{
	int	i;

	i = 0;
	while (i < 6)
		print_ascii_art_pixel(config, 10 + i++, 11, \
											config->textures->dark_green_pixel);
	print_ascii_art_pixel(config, 15, 10, \
											config->textures->dark_green_pixel);
	i = 0;
	while (i < 2)
		print_ascii_art_pixel(config, 15, 2 + i++, \
											config->textures->dark_green_pixel);
	print_ascii_art_pixel(config, 14, 3, \
											config->textures->dark_green_pixel);
	i = 0;
	while (i < 6)
		print_ascii_art_pixel(config, 13, 3 + i++, \
											config->textures->dark_green_pixel);
	print_ascii_art_pixel(config, 10, 3, \
											config->textures->dark_green_pixel);
}
