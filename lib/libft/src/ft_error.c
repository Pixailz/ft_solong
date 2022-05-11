/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 00:58:51 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/12 01:01:04 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/includes/ft_printf.h"
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_error(char *msg)
{
	if (errno)
	{
		perror(msg);
		exit(errno);
	}
	else
	{
		ft_printf("ERROR : %s\n", msg);
		exit(1);
	}
}
