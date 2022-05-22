/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 02:05:34 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/22 09:39:57 by brda-sil         ###   ########.fr       */
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
				print_ascii_art_pixel(config, 17 + i, 1 + j, GREEN);
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	while (i < 4)
		print_ascii_art_pixel(config, 19, 3 + i++, GREEN);
	i = 0;
	while (i < 4)
		print_ascii_art_pixel(config, 20, 5 + i++, GREEN);
}

void	print_ascii_n_shadow(t_main *config)
{
	int	i;

	print_ascii_art_pixel(config, 19, 2, DARK_GREEN);
	i = 0;
	while (i < 5)
		print_ascii_art_pixel(config, 19, 7 + i++, DARK_GREEN);
	print_ascii_art_pixel(config, 18, 11, DARK_GREEN);
	print_ascii_art_pixel(config, 20, 4, DARK_GREEN);
	i = 0;
	while (i < 10)
		print_ascii_art_pixel(config, 23, 2 + i++, DARK_GREEN);
	print_ascii_art_pixel(config, 22, 11, DARK_GREEN);
}
