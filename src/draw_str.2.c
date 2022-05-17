/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_str.2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 14:19:15 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/18 01:49:30 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_continue(t_main *config)
{
	ft_printf("Continuing game\n");
	config->p_current_map++;
	ft_printf("Player now on map %s\n", config->map_str[config->p_current_map]);
	put_str_log(config, "Continuing game ;)", GREEN);
	mlx_loop_end(config->mlx);
}

void	print_step_total(t_main *config)
{
	char	*tmp1;
	char	*tmp2;

	config->p_total_step += config->p_step;
	ft_printf("Total steps: %d\n", config->p_total_step);
	tmp1 = ft_itoa(config->p_total_step);
	tmp2 = ft_strjoin("Total steps: ", tmp1);
	free(tmp1);
	put_str_log(config, tmp2, GREEN);
	free(tmp2);
}
