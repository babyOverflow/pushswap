/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:01:30 by seonghyk          #+#    #+#             */
/*   Updated: 2022/06/10 19:23:28 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	print_format(int fd, t_Format *format)
{
	if (format->type_c == 'd' || format->type_c == 'i'
		|| format->type_c == 'u')
		return (print_format_decimal(fd, format));
	else if (format->type_c == 'x' || format->type_c == 'X'
		|| format->type_c == 'p')
		return (print_format_hex(fd, format));
	else if (format->type_c == 's')
		return (print_format_string(fd, format));
	else if (format->type_c == 'c')
		return (print_format_char(fd, format));
	else if (format->type_c == '%')
	{
		format->value.as_char = '%';
		return (print_format_char(fd, format));
	}
	else
		return (0);
}
