/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format_decimal_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:50:08 by seonghyk          #+#    #+#             */
/*   Updated: 2022/06/13 14:00:49 by seonghyk         ###   ########.fr       */
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

int	print_spaces(int fd, t_Format *format, t_Prefix *prefix, int arg_len)
{
	int	count;
	int	i;

	count = 0;
	if (!(format->flags & FMT_ZERO_PADDING))
	{
		count = format->padding - prefix->len;
	}
	if (format->precision > arg_len)
		count -= format->precision;
	else
		count -= arg_len;
	i = -1;
	while (++i < count)
		ft_putchar_fd(' ', fd);
	if (format->flags & FMT_BLANK_PADDING && prefix->len == 0
		&& i == 0 && format->type_c != 'u')
	{
		ft_putchar_fd(' ', fd);
		i++;
		format->padding--;
	}
	return (i);
}

int	print_zeros(int fd, t_Format *format, t_Prefix *prefix, int arg_len)
{
	int	count;
	int	i;

	count = 0;
	if (format->flags & FMT_ZERO_PADDING && !(format->flags & FMT_NEG_FILED))
	{
		count = format->padding - prefix->len;
		count -= arg_len;
	}
	if (format->precision >= 0)
		count = format->precision - arg_len;
	i = -1;
	while (++i < count)
		ft_putchar_fd('0', fd);
	return (i);
}

int	print_format_decimal(int fd, t_Format *format)
{
	t_Prefix		prefix;
	char			buf[60];
	int				len_arg;
	int				ret;

	if (format->value.as_int == 0 && format->precision == 0)
		len_arg = 0;
	else if (format->type_c == 'i' || format->type_c == 'd')
		len_arg = decimal_to_string(format->value.as_int, buf);
	else if (format->type_c == 'u')
		len_arg = unsigned_decimal_to_string(format->value.as_int, buf);
	else
		return (0);
	prefix = get_prefix(format);
	ret = 0;
	if (!(format->flags & FMT_NEG_FILED))
		ret += print_spaces(fd, format, &prefix, len_arg);
	ret += write(fd, prefix.str, prefix.len);
	ret += print_zeros(fd, format, &prefix, len_arg);
	ret += write(fd, buf, len_arg);
	if ((format->flags & FMT_NEG_FILED))
		ret += print_spaces(fd, format, &prefix, len_arg);
	return (ret);
}
