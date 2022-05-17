/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:24:22 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/17 03:31:42 by brda-sil         ###   ########.fr       */
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

void	init_log(t_main *config)
{
	int	i;

	config->log->current_pos = 0;
	config->log->max_length = config->width * LOG_BLOCK_LENGTH;
	config->log->line = (t_line **)malloc(sizeof(t_line *) * (LOG_LENGTH + 1));
	i = 0;
	while (i < LOG_LENGTH)
	{
		config->log->line[i] = (t_line *)malloc(sizeof(t_line));
		config->log->line[i]->str = malloc(sizeof(char) * \
											(config->log->max_length + 1));
		config->log->line[i]->color = 0x000000;
		i++;
	}
}

void	put_log_str_line(t_main *config, int pos)
{
	mlx_string_put(config->mlx, config->win, 0, \
				((pos + 1) * LOG_FONT_HEIGTH) - 5, \
				config->log->line[config->log->current_pos]->color, \
				config->log->line[config->log->current_pos]->str);
	if (config->log->current_pos != LOG_LENGTH)
		config->log->current_pos++;
}

void	put_log_str_black(t_main *config)
{
	int		i;

	i = 0;
	while (i < LOG_LENGTH)
	{
		mlx_string_put(config->mlx, config->win, 0, \
				((i + 1) * LOG_FONT_HEIGTH) - 5, \
				BLACK, config->log->line[i]->str);
		i++;
	}
	i = 1;
	while (i < LOG_LENGTH)
	{
		ft_strcpy(config->log->line[i - 1]->str, config->log->line[i]->str);
		config->log->line[i - 1]->color = config->log->line[i]->color;
		i++;
	}
}

void	put_log_str_defil(t_main *config)
{
	int	i;

	config->log->current_pos--;
	put_log_str_black(config);
	i = 0;
	while (i < LOG_LENGTH - 1)
	{
		mlx_string_put(config->mlx, config->win, 0, \
				((i + 1) * LOG_FONT_HEIGTH) - 5, \
				config->log->line[i]->color, \
				config->log->line[i]->str);
		i++;
	}
}

void	put_str_log(t_main *config, char *str, int color)
{
	put_separator_log(config);
	if (config->log->current_pos == LOG_LENGTH)
		put_log_str_defil(config);
	ft_strlcpy(config->log->line[config->log->current_pos]->str, str, \
													config->log->max_length);
	config->log->line[config->log->current_pos]->color = color;
	put_log_str_line(config, config->log->current_pos);
}
