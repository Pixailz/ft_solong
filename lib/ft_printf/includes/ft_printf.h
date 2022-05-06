/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:53:46 by brda-sil          #+#    #+#             */
/*   Updated: 2022/04/23 18:33:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// CONFIG
# define PARAMS_LIST "cspdiuxX%"
# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"

// LIBRARY
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

// MAIN
int	ft_printf(const char *format, ...);
int	ft_parse(va_list args, const char *format);
int	ft_checkparams(char c);
int	ft_sel_params(va_list args, char param_type);
int	ft_put_addr(va_list args);

// UTILS
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putnbr_u(unsigned int n);
int	ft_puthex(unsigned long n, char format);
int	ft_strlen(char *s);

#endif
