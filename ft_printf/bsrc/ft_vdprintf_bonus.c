/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:31:41 by seonghyk          #+#    #+#             */
/*   Updated: 2022/06/10 20:46:08 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

int	ft_dprint_varg(int fd, char *fmt, size_t *idx, va_list ap)
{
	int				ret;
	t_Format		format;

	format = t_format_create(&fmt[*idx], ap);
	if (format.is_valid == 0)
		return (write(fd, &fmt[(*idx)++], 1));
	ret = print_format(fd, &format);
	*idx += format.offset;
	return (ret);
}

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	char	*fmt;
	size_t	i;
	size_t	last;
	int		ret;

	fmt = (char *)format;
	last = 0;
	i = 0;
	ret = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			ret += write(fd, &fmt[last], i - last);
			ret += ft_dprint_varg(fd, fmt, &i, ap);
			last = i;
			continue ;
		}
		++i;
	}
	ret += write(fd, &fmt[last], i - last);
	return (ret);
}
