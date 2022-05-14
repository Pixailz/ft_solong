/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 05:04:46 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/14 05:13:24 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_3(t_main *config, int dir[4], int i, int j)
{
	if (dir[1] && dir[2] && dir[3])
		config->map_new[i][j] = 'N';
	else if (dir[2] && dir[3] && dir[0])
		config->map_new[i][j] = 'S';
	else if (dir[3] && dir[0] && dir[1])
		config->map_new[i][j] = '2';
	else if (dir[0] && dir[1] && dir[2])
		config->map_new[i][j] = 'W';
}

void	change_1(t_main *config, int dir[4], int i, int j)
{
	if (dir[0])
		config->map_new[i][j] = 'n';
	else if (dir[1])
		config->map_new[i][j] = 's';
	else if (dir[2])
		config->map_new[i][j] = '3';
	else if (dir[3])
		config->map_new[i][j] = 'w';
}

void	change_corner(t_main *config, int dir[4], int i, int j)
{
	if (dir[0] && dir[2])
		config->map_new[i][j] = '5';
	else if (dir[0] && dir[3])
		config->map_new[i][j] = '6';
	else if (dir[1] && dir[3])
		config->map_new[i][j] = '7';
	else if (dir[1] && dir[2])
		config->map_new[i][j] = '8';
}
