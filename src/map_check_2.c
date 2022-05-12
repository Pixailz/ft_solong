/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:27:05 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/12 18:32:45 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_minimum_point(t_main *config)
{
	if (config->nb_player != 1)
		return (0);
	if (config->nb_door < 1)
		return (0);
	if (config->nb_key < 1)
		return (0);
	return (1);
}
