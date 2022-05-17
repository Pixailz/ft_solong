/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_str.2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 14:19:15 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/17 09:42:01 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_continue(t_main *config)
{
	ft_printf("Continuing game\n");
	config->p_current_map++;
	ft_printf("Player now on map n%d\n", config->p_current_map);
	put_str_log(config, "Continuing game ;)", GREEN);
	mlx_loop_end(config->mlx);
}
