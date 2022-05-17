/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 02:57:50 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/15 22:37:50 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse_init_place_9(t_main *config, int i, int j)
{
	if (i == 0)
	{
		config->map_new[i][j] = '9';
		return (1);
	}
	if (i == config->height + 1)
	{
		config->map_new[i][j] = '9';
		return (1);
	}
	if (j == 0)
	{
		config->map_new[i][j] = '9';
		return (1);
	}
	if (j == config->width + 1)
	{
		config->map_new[i][j] = '9';
		return (1);
	}
	return (0);
}

static	void	parse_init_new_map(t_main *config)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	config->map_new = (char **)malloc(sizeof(char *) * (config->height + 3));
	while (i < config->height + 2)
	{
		config->map_new[i] = (char *)malloc(sizeof(char) * (config->width + 3));
		while (j < config->width + 2)
		{
			if (!parse_init_place_9(config, i, j))
				config->map_new[i][j] = config->map[i - 1][j - 1];
			j++;
		}
		j = 0;
		i++;
	}
	free_map(config);
	config->map_new_loaded = 1;
	config->map_loaded = 0;
}

static	void	get_direction(t_main *config, int dir[4], int i, int j)
{
	if (check_is_wall(config->map_new[i - 1][j]))
		dir[0] = 1;
	if (check_is_wall(config->map_new[i + 1][j]))
		dir[1] = 1;
	if (check_is_wall(config->map_new[i][j + 1]))
		dir[2] = 1;
	if (check_is_wall(config->map_new[i][j - 1]))
		dir[3] = 1;
}

static	void	check_wall_nearby(t_main *config, int i, int j)
{
	int	dir[4];

	dir[0] = 0;
	dir[1] = 0;
	dir[2] = 0;
	dir[3] = 0;
	get_direction(config, dir, i, j);
	if (dir[0] && dir[1] && dir[2] && dir[3])
		config->map_new[i][j] = '4';
	else if ((dir[0] && dir[1] && dir[2]) || (dir[1] && dir[2] && dir[3]) || \
			(dir[2] && dir[3] && dir[0]) || (dir[3] && dir[0] && dir[1]))
		change_3(config, dir, i, j);
	else if ((dir[0] && dir[2]) || (dir[0] && dir[3]) || \
			(dir[1] && dir[2]) || (dir[1] && dir[3]))
		change_corner(config, dir, i, j);
	else if (dir[2] && dir[3])
		config->map_new[i][j] = 'h';
	else if (dir[0] && dir[1])
		config->map_new[i][j] = 'v';
	else if (dir[0] || dir[1] || dir[2] || dir[3])
		change_1(config, dir, i, j);
}

void	parse_wall(t_main *config)
{
	int	i;
	int	j;

	parse_init_new_map(config);
	i = 0;
	j = 0;
	while (i < config->height)
	{
		while (j < config->width)
		{
			if (config->map_new[i + 1][j + 1] == '1')
				check_wall_nearby(config, i + 1, j + 1);
			j++;
		}
		j = 0;
		i++;
	}
	if (DEBUG)
	{
		ft_printf("wall_parsed_map\n");
		debug_print_map_without_9(config);
	}
}
