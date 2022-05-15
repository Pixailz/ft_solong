/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 14:19:15 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/15 14:19:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_close(t_main *config)
{
	ft_printf("Closing game.\n");
	mlx_string_put(config->mlx, config->win, 0, 5 * 14, 0xff0000, \
															"Closing game.");
	mlx_loop_end(config->mlx);
}

void	print_retry(t_main *config)
{
	ft_printf("Restart game.\n");
	mlx_string_put(config->mlx, config->win, 0, 5 * 14, 0xff0000, \
															"Restart game.");
	config->retry = 1;
	mlx_loop_end(config->mlx);
}

void	retry_choose(t_main *config)
{
	ft_printf("Press R to retry. ESC to exit\n");
	mlx_string_put(config->mlx, config->win, 0, 3 * 14, 0x00ff00, \
											"Press R to retry,");
	mlx_string_put(config->mlx, config->win, 0, 4 * 14, 0x00ff00, \
											"ESC to exit.");
}

void	print_before_win_loose(t_main *config)
{
	if (config->p_win == 1)
	{
		ft_printf("player has win with %d steps\n", config->p_step);
		mlx_string_put(config->mlx, config->win, 0, 2 * 14, 0x00ff00, \
															"Player has win");
	}
	else if (config->p_win == -1)
	{
		ft_printf("player has loose\n");
		mlx_string_put(config->mlx, config->win, 0, 2 * 14, 0xff0000, \
															"Player has loose");
	}
	retry_choose(config);
}
