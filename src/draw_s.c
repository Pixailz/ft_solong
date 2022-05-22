/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:54:12 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/22 11:07:08 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	print_ascii_s_mid(t_main *config)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < 2)
	{
		while (i < 10)
		{
			if (i < 2 || (i > 3 && i < 6) || i > 7)
				print_ascii_art_pixel(config, 27 + j, i + 1, \
												config->textures->red_pixel);
			i++;
		}
		i = 0;
		j++;
	}
	i = 0;
	while (i < 10)
	{
		if (i < 2 || i > 3)
			print_ascii_art_pixel(config, 29, i + 1, \
											config->textures->red_pixel);
		i++;
	}
}

static	void	print_ascii_s_end(t_main *config)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (i < 2 || (i > 4 && i < 9))
			print_ascii_art_pixel(config, 30, i + 1, \
											config->textures->red_pixel);
		i++;
	}
}

void	print_ascii_s(t_main *config)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		if (i < 4 || i > 6)
			print_ascii_art_pixel(config, 25, i + 2, \
											config->textures->red_pixel);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (i < 6 || i > 7)
			print_ascii_art_pixel(config, 26, i + 1, \
											config->textures->red_pixel);
		i++;
	}
	print_ascii_s_mid(config);
	print_ascii_s_end(config);
}

void	print_ascii_s_shadow(t_main *config)
{
	int	i;

	i = 0;
	while (i < 5)
		print_ascii_art_pixel(config, i++ + 27, 3, \
											config->textures->dark_red_pixel);
	print_ascii_art_pixel(config, 27, 4, \
											config->textures->dark_red_pixel);
	print_ascii_art_pixel(config, 31, 2, \
											config->textures->dark_red_pixel);
	i = 0;
	while (i < 5)
		print_ascii_art_pixel(config, i++ + 26, 11, \
											config->textures->dark_red_pixel);
	i = 0;
	while (i < 4)
		print_ascii_art_pixel(config, 31, i++ + 7, \
											config->textures->dark_red_pixel);
	print_ascii_art_pixel(config, 30, 10, \
											config->textures->dark_red_pixel);
	print_ascii_art_pixel(config, 27, 7, \
											config->textures->dark_red_pixel);
	print_ascii_art_pixel(config, 28, 7, \
											config->textures->dark_red_pixel);
}
