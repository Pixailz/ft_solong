/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:32:01 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/15 16:09:50 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

int	check_ext(char *file_name)
{
	int	size;

	size = ft_strlen(file_name);
	if (file_name[size - 1] == 'r' && \
		file_name[size - 2] == 'e' && \
		file_name[size - 3] == 'b' && \
		file_name[size - 4] == '.')
		return (1);
	return (0);
}

char	*get_all_file(char *file_name)
{
	int		file;
	char	*line;
	char	*all_file;

	file = open(file_name, O_RDONLY);
	if (file == -1)
		ft_error(file_name);
	line = get_next_line(file);
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

void	parse_map(t_main *config, char *file_name)
{
	char	*all_file;

	if (!check_ext(file_name))
		ft_error("wrong extansion");
	all_file = get_all_file(file_name);
	config->height = ft_get_words(all_file, '\n');
	config->map = ft_split(all_file, '\n');
	config->map_loaded = 1;
	config->width = ft_strlen(config->map[0]);
	free(all_file);
}
