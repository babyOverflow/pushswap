/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_format_set_arg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:54:03 by seonghyk          #+#    #+#             */
/*   Updated: 2022/06/07 15:21:58 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	t_format_set_arg_pointer(t_Format *format, void *arg)
{
	format->value.as_pointer = arg;
}

void	t_format_set_arg_uint(t_Format *format, unsigned int arg)
{
	format->value.as_uint = arg;
}

void	t_format_set_arg_int(t_Format *format, int arg)
{
	format->value.as_int = arg;
}
