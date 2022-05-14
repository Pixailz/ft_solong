/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 00:20:34 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/14 16:16:52 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* ########################################################################## */
/* CONFIG */
/* ###### */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0x100
# endif
# ifndef MAX_FD
#  define MAX_FD 0x400
# endif

/* ########################################################################## */

/* ########################################################################## */
/* LIBRARY */
/* ####### */

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

/* ########################################################################## */

/* ########################################################################## */
/* GET_NEXT_LINE */
/* ############# */

char	*get_next_line(int fd);
char	*ft_line(char *buf);
char	*ft_stash(char *s);
char	*ft_read(int fd, char *buf);

// UTILS
char	*ft__memchr(char *buf, unsigned char c);
size_t	ft__strlen(char *s);
char	*ft__memjoin(char *s1, char *s2);

/* ########################################################################## */

#endif
