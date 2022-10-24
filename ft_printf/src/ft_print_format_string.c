/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:13:21 by seonghyk          #+#    #+#             */
/*   Updated: 2022/06/11 13:47:00 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	print_format_string(int fd, t_Format *format)
{
	int				len_arg;
	int				ret;

	if (format->value.as_pointer == NULL)
		format->value.as_pointer = "(null)";
	ret = 0;
	len_arg = ft_strlen(format->value.as_pointer);
	ret += write(fd, format->value.as_pointer, len_arg);
	return (ret);
}
