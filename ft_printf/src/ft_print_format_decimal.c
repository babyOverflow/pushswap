/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format_decimal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:50:08 by seonghyk          #+#    #+#             */
/*   Updated: 2022/06/13 13:41:11 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "t_format.h"
#include "libft.h"

t_Prefix	get_prefix(t_Format *format)
{
	if (format->type_c != 'u')
	{
		if (format->value.as_int < 0)
			return ((t_Prefix){1, "-"});
		else if (format->flags & FMT_SIGN_ALWAYS)
			return ((t_Prefix){1, "+"});
		else
			return ((t_Prefix){0, NULL});
	}
	return ((t_Prefix){0, NULL});
}

int	print_format_decimal(int fd, t_Format *format)
{
	t_Prefix		prefix;
	char			buf[60];
	int				len_arg;
	int				ret;

	if (format->type_c == 'i' || format->type_c == 'd')
		len_arg = decimal_to_string(format->value.as_int, buf);
	else if (format->type_c == 'u')
		len_arg = unsigned_decimal_to_string(format->value.as_int, buf);
	else
		return (0);
	prefix = get_prefix(format);
	ret = 0;
	ret += write(fd, prefix.str, prefix.len);
	if (!(format->value.as_int == 0 && format->precision == 0))
		ret += write(fd, buf, len_arg);
	return (ret);
}
