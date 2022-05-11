/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:32:01 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/11 22:53:27 by brda-sil         ###   ########.fr       */
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
		file_name[size - 1] == '.')
		return (1);
	return (0);
}

void	parse_map(t_main *config, char *file_name)
{
	int	*line;
	int	file;
	int	i;

	if (!check_ext(file_name))
		ft_error("wrong extansion");
	file = open(file_name, O_RDONLY);
	if (file == -1)
		ft_error(file_name);
	line = get_next_line(file);
	config->width = ft_strlen(line);
	i = 0;
	while (line)
	{
		config->map;
	}
}
