/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_multiple_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:27:47 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/18 01:43:12 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pre_init(t_main *config)
{
	config->texture_loaded = 0;
	config->retry = 1;
	config->p_current_map = 0;
	config->p_total_step = 0;
}

void	init_multiple_map(t_main *config, char **argv)
{
	int	i;

	config->p_current_map = 0;
	config->map_str = (char **)malloc(sizeof(char *) * (config->nb_map + 1));
	i = 0;
	while (i < config->nb_map)
	{
		config->map_str[i] = (char *)malloc(sizeof(char *) * \
												(ft_strlen(argv[i + 1]) + 1));
		ft_strcpy(config->map_str[i], argv[i + 1]);
		i++;
	}
}
