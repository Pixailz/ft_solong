/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:24:22 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/17 08:16:44 by brda-sil         ###   ########.fr       */
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

void	put_log_duel_5(t_main *config)
{
	char	*tmp1;
	char	*tmp2;

	put_str_log(config, "Player fight against", WHITE);
	tmp1 = ft_itoa(config->nb_figth);
	tmp2 = ft_strjoin(tmp1, " enemy");
	free(tmp1);
	put_str_log(config, tmp2, WHITE);
	free(tmp2);
}

void	put_log_duel_other(t_main *config)
{
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;

	tmp1 = ft_itoa(config->nb_figth);
	tmp2 = ft_strjoin("Player fight against ", tmp1);
	free(tmp1);
	tmp3 = ft_strjoin(tmp2, " enemy");
	free(tmp2);
	put_str_log(config, tmp3, WHITE);
	free(tmp3);
}

void	put_log_duel_kill(t_main *config, int x, int y)
{
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;

	tmp1 = ft_itoa(y);
	tmp2 = ft_strjoin("Enemy at [", tmp1);
	free(tmp1);
	tmp1 = ft_strjoin(tmp2, ",");
	free(tmp2);
	tmp2 = ft_itoa(config->height - x + 1);
	tmp3 = ft_strjoin(tmp1, tmp2);
	free(tmp1);
	free(tmp2);
	tmp2 = ft_strjoin(tmp3, "] die");
	free(tmp3);
	put_str_log(config, tmp2, WHITE);
	free(tmp2);
}
