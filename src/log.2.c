/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:24:22 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/17 04:34:42 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_separator_log(t_main *config)
{
	int	i;

	i = 0;
	while (i < LOG_LENGTH * LOG_FONT_HEIGTH)
	{
		mlx_pixel_put(config->mlx, config->win, \
			(LOG_FONT_WIDTH * LOG_BLOCK_LENGTH) * config->width, i++, WHITE);
	}
}
