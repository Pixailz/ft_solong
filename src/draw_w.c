/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_w.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:35:08 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/22 09:37:30 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_ascii_w_shadow(t_main *config)
{
	int	i;

	i = 0;
	while (i < 6)
		print_ascii_art_pixel(config, 3, i++ + 2, DARK_GREEN);
	i = 0;
	while (i < 6)
		print_ascii_art_pixel(config, 5, i++ + 2, DARK_GREEN);
	i = 0;
	while (i < 9)
		print_ascii_art_pixel(config, 8, i++ + 2, DARK_GREEN);
	print_ascii_art_pixel(config, 7, 10, DARK_GREEN);
	print_ascii_art_pixel(config, 7, 11, DARK_GREEN);
	print_ascii_art_pixel(config, 6, 11, DARK_GREEN);
	print_ascii_art_pixel(config, 4, 10, DARK_GREEN);
	print_ascii_art_pixel(config, 4, 11, DARK_GREEN);
	print_ascii_art_pixel(config, 3, 11, DARK_GREEN);
}

void	print_ascii_w(t_main *config)
{
	int	i;

	i = 0;
	while (i < 9)
		print_ascii_art_pixel(config, 1, i++ + 1, GREEN);
	i = 0;
	while (i < 10)
		print_ascii_art_pixel(config, 2, i++ + 1, GREEN);
	i = 0;
	while (i < 3)
		print_ascii_art_pixel(config, 3, i++ + 8, GREEN);
	i = 0;
	while (i < 9)
		print_ascii_art_pixel(config, 4, i++ + 1, GREEN);
	i = 0;
	while (i < 3)
		print_ascii_art_pixel(config, 5, i++ + 8, GREEN);
	i = 0;
	while (i < 10)
		print_ascii_art_pixel(config, 6, i++ + 1, GREEN);
	i = 0;
	while (i < 9)
		print_ascii_art_pixel(config, 7, i++ + 1, GREEN);
}
