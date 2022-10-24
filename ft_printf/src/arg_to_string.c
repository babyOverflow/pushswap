/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:55:33 by seonghyk          #+#    #+#             */
/*   Updated: 2022/06/10 20:19:12 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	hexadecimal_to_string(unsigned long p, char *buf, int is_uppercase)
{
	int				len;
	int				i;

	ft_ultoa_base(p, buf, 16);
	len = ft_strlen(buf);
	i = -1;
	if (is_uppercase)
		while (++i < len)
			buf[i] = ft_toupper(buf[i]);
	return (len);
}

int	unsigned_decimal_to_string(unsigned int d, char *buf)
{
	int				len;

	ft_uitoa_base(d, buf, 10);
	len = ft_strlen(buf);
	return (len);
}

int	decimal_to_string(int d, char *buf)
{
	int				len;
	unsigned int	ud;

	ud = d;
	if (d < 0)
		ud = -d;
	ft_uitoa_base(ud, buf, 10);
	len = ft_strlen(buf);
	return (len);
}

int	chr_to_string(char c, char *buf)
{
	buf[0] = c;
	buf[1] = '\0';
	return (1);
}
