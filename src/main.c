/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:00:32 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/09 20:04:36 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

int	main(void)
{
	void	*mlx;
	void	*windows;
	int		x;

	x = 10;
	mlx = mlx_init();
	windows = mlx_new_window(mlx, 800, 400, "test");
	mlx_xpm_file_to_image(mlx, "img/test.xpm", &x, &x);
	usleep(5000000);
	mlx_destroy_window(mlx, windows);
	mlx_destroy_display(mlx);
	free(mlx);
	return (0);
}
