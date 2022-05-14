/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:27:05 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/14 05:17:17 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_is_wall(char block)
{
	if (block == '1' || block == 'h' || block == 'v' || block == 'N' || \
		block == 'S' || block == '2' || block == 'W' || block == 'n' || \
		block == 's' || block == '3' || block == 'w' || block == '5' || \
		block == '6' || block == '7' || block == '8')
		return (1);
	return (0);
}

void	exit_minimum_point(int return_code)
{
	if (return_code == 1)
		ft_error("have multiple player");
	if (return_code == 1)
		ft_error("have no player");
	if (return_code == 3)
		ft_error("have no door");
	if (return_code == 4)
		ft_error("have no key");
}

int	check_minimum_point(t_main *config)
{
	if (config->nb_player > 1)
		return (1);
	if (config->nb_player < 1)
		return (2);
	if (config->nb_door < 1)
		return (3);
	if (config->nb_key < 1)
		return (4);
	return (0);
}
