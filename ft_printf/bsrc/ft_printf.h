/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:45:43 by seonghyk          #+#    #+#             */
/*   Updated: 2022/06/10 20:44:41 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "t_format.h"

int		print_format_decimal(int fd, t_Format *format);
int		print_format_string(int fd, t_Format *format);
int		print_format_char(int fd, t_Format *format);
int		print_format_hex(int fd, t_Format *format);
int		print_format(int fd, t_Format *format);

int		ft_printf(const char *format, ...);
int		ft_vdprintf(int fd, const char *format, va_list ap);
#endif
