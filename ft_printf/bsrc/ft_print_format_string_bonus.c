/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:13:21 by seonghyk          #+#    #+#             */
/*   Updated: 2022/06/10 19:44:11 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	print_str_spaces(int fd, t_Format *format, int arg_len)
{
	int	count;
	int	i;

	count = 0;
	if (!(format->flags & FMT_ZERO_PADDING))
	{
		count = format->padding;
	}
	count -= arg_len;
	i = -1;
	while (++i < count)
		ft_putchar_fd(' ', fd);
	return (i);
}

int	print_str_zeros(int fd, t_Format *format, int arg_len)
{
	int	count;
	int	i;

	count = 0;
	if (format->flags & FMT_ZERO_PADDING && !(format->flags & FMT_NEG_FILED))
	{
		count = format->padding;
		count -= arg_len;
	}
	i = -1;
	while (++i < count)
		ft_putchar_fd('0', fd);
	return (i);
}

int	print_format_string(int fd, t_Format *format)
{
	int				len_arg;
	int				ret;

	if (format->value.as_pointer == NULL)
		format->value.as_pointer = "(null)";
	ret = 0;
	len_arg = ft_strlen(format->value.as_pointer);
	if (format->precision >= 0 && len_arg > format->precision)
		len_arg = format->precision;
	if (!(format->flags & FMT_NEG_FILED))
		ret += print_str_spaces(fd, format, len_arg);
	ret += print_str_zeros(fd, format, len_arg);
	ret += write(fd, format->value.as_pointer, len_arg);
	if (format->flags & FMT_NEG_FILED)
		ret += print_str_spaces(fd, format, len_arg);
	return (ret);
}
