/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_l.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:40:31 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/21 21:35:38 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_ascii_l_shadow(int global_offset, t_main *config)
{
	int	i;

	i = 0;
	while (i < 7)
		print_ascii_art_pixel(config, 3 + global_offset, i++ + 2, DARK_RED);
	i = 0;
	while (i < 6)
	{
		print_ascii_art_pixel(config, i++ + 2 + global_offset, 11, DARK_RED);
	}
	print_ascii_art_pixel(config, 7 + global_offset, 10, DARK_RED);
}

void	print_ascii_l(int global_offset, t_main *config)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < 3)
	{
		while (j < 10)
			print_ascii_art_pixel(config, i + global_offset, j++ + 1, RED);
		j = 0;
		i++;
	}
	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 2)
			print_ascii_art_pixel(config, i + 3 + global_offset, j++ + 9, RED);
		j = 0;
		i++;
	}
}
