/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:13:21 by seonghyk          #+#    #+#             */
/*   Updated: 2022/06/10 19:50:43 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	print_chr_spaces(int fd, t_Format *format, int arg_len)
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

int	print_chr_zeros(int fd, t_Format *format, int arg_len)
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

int	print_format_char(int fd, t_Format *format)
{
	const int		len_arg = 1;
	int				ret;

	ret = 0;
	if (!(format->flags & FMT_NEG_FILED))
		ret += print_chr_spaces(fd, format, len_arg);
	ret += print_chr_zeros(fd, format, len_arg);
	ret += write(fd, &format->value.as_char, len_arg);
	if (format->flags & FMT_NEG_FILED)
		ret += print_chr_spaces(fd, format, len_arg);
	return (ret);
}
