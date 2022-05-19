/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:32:01 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/19 12:26:24 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

static	int	check_ext(t_main *config)
{
	int	size;

	size = ft_strlen(config->map_str[config->p_current_map]);
	if (config->map_str[config->p_current_map][size - 1] == 'r' && \
		config->map_str[config->p_current_map][size - 2] == 'e' && \
		config->map_str[config->p_current_map][size - 3] == 'b' && \
		config->map_str[config->p_current_map][size - 4] == '.')
		return (1);
	return (0);
}

static	int	open_file(t_main *config)
{
	int	file;

	file = open(config->map_str[config->p_current_map], O_RDONLY);
	if (file == -1)
	{
		free_multiple_map(config);
		ft_error("Map not found");
	}
	return (file);
}

static	char	*get_all_file(t_main *config)
{
	int		file;
	char	*line;
	char	*all_file;

	file = open_file(config);
	line = get_next_line(file);
	if (!line)
		free_empty_file(config);
	all_file = malloc(sizeof(char) * ft_strlen(line) + 1);
	all_file = ft_strcpy(all_file, line);
	while (line)
	{
		free(line);
		line = get_next_line(file);
		if (!line)
			break ;
		all_file = ft__memjoin(all_file, line);
	}
	free(line);
	close(file);
	return (all_file);
}

void	parse_map(t_main *config)
{
	char	*all_file;

	if (!check_ext(config))
		ft_error("wrong extansion");
	all_file = get_all_file(config);
	config->height = ft_get_words(all_file, '\n');
	config->map = ft_split(all_file, '\n');
	config->map_loaded = 1;
	config->width = ft_strlen(config->map[0]);
	free(all_file);
}
