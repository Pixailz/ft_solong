/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_e.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:51:02 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/21 21:39:14 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_ascii_e_end(int global_offset, t_main *config)
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
				print_ascii_art_pixel(config, 35 + i + global_offset, j + 1, \
																		RED);
			j++;
		}
		j = 0;
		i++;
	}
}

void	print_ascii_e(int global_offset, t_main *config)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 2)
	{
		while (j < 10)
		{
			print_ascii_art_pixel(config, 33 + i + global_offset, j++ + 1, RED);
		}
		j = 0;
		i++;
	}
	print_ascii_e_end(global_offset, config);
}

void	print_ascii_e_shadow(int global_offset, t_main *config)
{
	int	i;

	i = 0;
	while (i < 5)
		print_ascii_art_pixel(config, 35 + i++ + global_offset, 3, DARK_RED);
	print_ascii_art_pixel(config, 39 + global_offset, 2, DARK_RED);
	print_ascii_art_pixel(config, 35 + global_offset, 4, DARK_RED);
	i = 0;
	while (i < 5)
		print_ascii_art_pixel(config, 35 + i++ + global_offset, 7, DARK_RED);
	print_ascii_art_pixel(config, 39 + global_offset, 6, DARK_RED);
	print_ascii_art_pixel(config, 35 + global_offset, 8, DARK_RED);
	i = 0;
	while (i < 6)
		print_ascii_art_pixel(config, 34 + i++ + global_offset, 11, DARK_RED);
	print_ascii_art_pixel(config, 39 + global_offset, 10, DARK_RED);
}
