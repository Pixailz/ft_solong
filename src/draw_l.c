/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:40:31 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/22 10:56:21 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_ascii_l_shadow(t_main *config)
{
	int	i;

	i = 0;
	while (i < 7)
		print_ascii_art_pixel(config, 3, i++ + 2, \
											config->textures->dark_red_pixel);
	i = 0;
	while (i < 6)
		print_ascii_art_pixel(config, i++ + 2, 11, \
											config->textures->dark_red_pixel);
	print_ascii_art_pixel(config, 7, 10, config->textures->dark_red_pixel);
}

void	print_ascii_l(t_main *config)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < 3)
	{
		while (j < 10)
			print_ascii_art_pixel(config, i, j++ + 1, \
												config->textures->red_pixel);
		j = 0;
		i++;
	}
	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 2)
			print_ascii_art_pixel(config, i + 3, j++ + 9, \
												config->textures->red_pixel);
		j = 0;
		i++;
	}
}
