/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:25:30 by seonghyk          #+#    #+#             */
/*   Updated: 2022/05/16 11:33:06 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static struct s_number_info	
	_ft_create_uint_info_base(unsigned int n, char *buf_digits, int base)
{
	struct s_number_info	info;
	unsigned int			number;
	int						count;
	const char				digits_table[] = {
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
	};

	info.is_nag = 0;
	if (n < 0)
		info.is_nag = 1;
	number = n;
	if (n < 0)
		number = -n;
	count = 0;
	while (number > 0)
	{
		buf_digits[count++] = digits_table[number % base];
		number /= base;
	}
	info.count = count;
	info.buf_digits = buf_digits;
	return (info);
}

static char	*zero(char *str)
{
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_uitoa_base(unsigned int n, char *str, int base)
{
	struct s_number_info	info;
	char					buf[65];
	int						idx;

	if (n == 0)
		return (zero(str));
	info = _ft_create_uint_info_base(n, buf, base);
	idx = 0;
	str[info.count--] = '\0';
	while (info.count > 0)
		str[idx++] = buf[info.count--];
	str[idx] = buf[info.count];
	return (str);
}
