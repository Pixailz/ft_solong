/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:54:12 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/21 21:41:19 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_ascci_s_mid(int global_offset, t_main *config)
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
				print_ascii_art_pixel(config, 27 + j + global_offset, i + 1, \
																		RED);
			i++;
		}
		i = 0;
		j++;
	}
	i = 0;
	while (i < 10)
	{
		if (i < 2 || i > 3)
			print_ascii_art_pixel(config, 29 + global_offset, i + 1, RED);
		i++;
	}
}

void	print_ascii_s(int global_offset, t_main *config)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		if (i < 4 || i > 6)
			print_ascii_art_pixel(config, 25 + global_offset, i + 2, RED);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (i < 6 || i > 7)
			print_ascii_art_pixel(config, 26 + global_offset, i + 1, RED);
		i++;
	}
	print_ascci_s_mid(global_offset, config);
	i = 0;
	while (i < 10)
	{
		if (i < 2 || (i > 4 && i < 9))
			print_ascii_art_pixel(config, 30 + global_offset, i + 1, RED);
		i++;
	}
}

void	print_ascii_s_shadow(int global_offset, t_main *config)
{
	int	i;

	i = 0;
	while (i < 5)
		print_ascii_art_pixel(config, i++ + 27 + global_offset, 3, DARK_RED);
	print_ascii_art_pixel(config, 27 + global_offset, 4, DARK_RED);
	print_ascii_art_pixel(config, 31 + global_offset, 2, DARK_RED);
	i = 0;
	while (i < 5)
		print_ascii_art_pixel(config, i++ + 26 + global_offset, 11, DARK_RED);
	i = 0;
	while (i < 4)
		print_ascii_art_pixel(config, 31 + global_offset, i++ + 7, DARK_RED);
	print_ascii_art_pixel(config, 30 + global_offset, 10, DARK_RED);
	print_ascii_art_pixel(config, 27 + global_offset, 7, DARK_RED);
	print_ascii_art_pixel(config, 28 + global_offset, 7, DARK_RED);
}
