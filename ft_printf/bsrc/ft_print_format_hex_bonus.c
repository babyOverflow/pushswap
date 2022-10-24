/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format_hex_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:50:08 by seonghyk          #+#    #+#             */
/*   Updated: 2022/06/13 13:49:19 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_Prefix	get_hex_prefix(t_Format *format)
{
	if (format->type_c == 'p')
		return ((t_Prefix){2, "0x"});
	if (format->value.as_int == 0)
		return ((t_Prefix){0, NULL});
	if (format->type_c == 'x' && format->flags & FMT_ALTER_FORM)
		return ((t_Prefix){2, "0x"});
	if (format->type_c == 'X' && format->flags & FMT_ALTER_FORM)
		return ((t_Prefix){2, "0X"});
	return ((t_Prefix){0, NULL});
}

int	print_hex_spaces(int fd, t_Format *format, t_Prefix *prefix, int arg_len)
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
	return (i);
}

int	print_hex_zeros(int fd, t_Format *format, t_Prefix *prefix, int arg_len)
{
	int	count;
	int	i;

	count = 0;
	if (format->flags & FMT_ZERO_PADDING && !(format->flags & FMT_NEG_FILED))
	{
		count = format->padding - prefix->len;
		count -= arg_len;
	}
	if (format->precision > 0)
		count = format->precision - arg_len;
	i = -1;
	while (++i < count)
		ft_putchar_fd('0', fd);
	return (i);
}

int	print_format_hex(int fd, t_Format *format)
{
	t_Prefix		prefix;
	char			buf[60];
	int				len_arg;
	int				ret;

	if (format->value.as_int == 0 && format->precision == 0)
		len_arg = 0;
	else if (format->type_c == 'x')
		len_arg = hexadecimal_to_string(format->value.as_uint, buf, 0);
	else if (format->type_c == 'X')
		len_arg = hexadecimal_to_string(format->value.as_uint, buf, 1);
	else if (format->type_c == 'p')
		len_arg = hexadecimal_to_string(format->value.as_ulong, buf, 0);
	else
		return (0);
	prefix = get_hex_prefix(format);
	ret = 0;
	if (!(format->flags & FMT_NEG_FILED))
		ret += print_hex_spaces(fd, format, &prefix, len_arg);
	ret += write(fd, prefix.str, prefix.len);
	ret += print_hex_zeros(fd, format, &prefix, len_arg);
	ret += write(fd, buf, len_arg);
	if ((format->flags & FMT_NEG_FILED))
		ret += print_hex_spaces(fd, format, &prefix, len_arg);
	return (ret);
}
