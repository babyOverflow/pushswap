/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:13:21 by seonghyk          #+#    #+#             */
/*   Updated: 2022/06/11 13:48:29 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	print_format_char(int fd, t_Format *format)
{
	const int		len_arg = 1;
	int				ret;

	ret = 0;
	ret += write(fd, &format->value.as_char, len_arg);
	return (ret);
}
