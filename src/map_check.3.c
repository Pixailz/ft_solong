/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:27:05 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/17 20:50:17 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_first_part(t_main *config)
{
	if (!check_wrong_point(config))
	{
		config->retry = 0;
		free_entry_point(config);
		ft_error("Wrong point on the map");
	}
	if (!check_width(config))
	{
		config->retry = 0;
		free_entry_point(config);
		ft_error("Map is not a square");
	}
}

void	check_second_part(t_main *config)
{
	int	return_code;

	if (!check_surrounded(config))
	{
		config->retry = 0;
		free_entry_point(config);
		ft_error("Map no surrounded");
	}
	return_code = check_minimum_point(config);
	if (return_code)
	{
		config->retry = 0;
		free_entry_point(config);
		exit_minimum_point(return_code);
	}
}
