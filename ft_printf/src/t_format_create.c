/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_format_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:51:55 by seonghyk          #+#    #+#             */
/*   Updated: 2022/06/11 13:44:46 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "t_format.h"

t_Format	*draw_arg_from(t_Format *format, char *fmt, va_list ap)
{
	char	c;

	c = fmt[format->offset];
	format->type_c = c;
	if (c == 'c' || c == 'i' || c == 'd')
		t_format_set_arg_int(format, va_arg(ap, int));
	else if (c == 'u' || c == 'x' || c == 'X')
		t_format_set_arg_uint(format, va_arg(ap, unsigned int));
	else if (c == 'p' || c == 's')
		t_format_set_arg_pointer(format, va_arg(ap, void *));
	else if (c == '%')
		;
	else
		format->is_valid = 0;
	format->type_c = c;
	format->offset++;
	return (format);
}

t_Format	t_format_create(char *fmt, va_list ap)
{
	t_Format	format;

	if (*fmt != '%')
		return ((t_Format){.is_valid = 0});
	format = (t_Format){
		.is_valid = 1, .offset = 1, .flags = 0, .precision = -1,
	};
	draw_arg_from(&format, fmt, ap);
	return (format);
}
