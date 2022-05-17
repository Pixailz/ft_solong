/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 14:19:15 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/17 04:28:10 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_close(t_main *config)
{
	ft_printf("Closing game\n");
	put_str_log(config, "Closing game", RED);
	config->retry = 0;
	config->is_finished = 1;
	mlx_loop_end(config->mlx);
}

void	print_retry(t_main *config)
{
	ft_printf("Restart game\n");
	put_str_log(config, "Restart game", GREEN);
	mlx_loop_end(config->mlx);
}

void	retry_choose(t_main *config)
{
	ft_printf("Press R to retry ESC to exit\n");
	if (config->width == 5)
	{
		put_str_log(config, "Press R to retry", GREEN);
		put_str_log(config, "ESC to exit", GREEN);
	}
	else
		put_str_log(config, "Press R to retry ESC to exit", GREEN);
}

void	print_win_step(t_main *config)
{
	char	*tmp;
	char	*tmp2;

	ft_printf("Player has win, step used: %d\n", config->p_step);
	if (config->width == 5)
	{
		put_str_log(config, "Player has win,", GREEN);
		tmp = ft_itoa(config->p_step);
		tmp2 = ft_strjoin("Step used: ", tmp);
		put_str_log(config, tmp2, GREEN);
	}
	else
	{
		tmp = ft_itoa(config->p_step);
		tmp2 = ft_strjoin("Player has win, step used: ", tmp);
		put_str_log(config, tmp2, GREEN);
	}
	free(tmp);
	free(tmp2);
}

void	print_before_win_loose(t_main *config)
{
	if (config->p_win == 1)
		print_win_step(config);
	else if (config->p_win == -1)
	{
		ft_printf("player has loose\n");
		put_str_log(config, "player has loose", RED);
	}
	retry_choose(config);
}
