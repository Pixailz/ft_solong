/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 14:20:57 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/17 10:07:13 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	debug_print_map_without_9(t_main *config)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= config->height - 1)
	{
		while (j <= config->width - 1)
		{
			if (j == 0)
				ft_printf("   %c", config->map_new[i + 1][j + 1]);
			else if (j != config->width - 1)
				ft_printf("%c", config->map_new[i + 1][j + 1]);
			else
				ft_printf("%c\n", config->map_new[i + 1][j + 1]);
			j++;
		}
		j = 0;
		i++;
	}
}

void	debug_print_map_with_9(t_main *config)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= config->height + 1)
	{
		while (j <= config->width + 1)
		{
			if (j != config->width + 1)
				ft_printf("%c", config->map_new[i][j]);
			else
				ft_printf("%c\n", config->map_new[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
}
