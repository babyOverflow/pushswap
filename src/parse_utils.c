/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:09:46 by seonghyk          #+#    #+#             */
/*   Updated: 2022/10/24 13:58:36 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	__ft_isspace(int c)
{
	if ((9 <= c && c <= 13) || c == ' ')
		return (1);
	return (0);
}

long	ft_atoi_l(const char *str)
{
	int		idx;
	long	ret;
	int		is_neg;

	idx = 0;
	while (__ft_isspace(str[idx]))
		idx++;
	is_neg = 0;
	if ((str[idx] == '-' || str[idx] == '+'))
		if (str[idx++] == '-')
			is_neg = 1;
	if (ft_isdigit(str[idx]) == 0)
		return (0);
	ret = str[idx++] - '0';
	while (ft_isdigit(str[idx]) != 0)
	{
		ret *= 10;
		ret += str[idx++] - '0';
		if (ret < 0)
			return (is_neg - 1);
	}
	if (is_neg == 1)
		return (-ret);
	return (ret);
}

void	exit_invalid_input(int error_code)
{
	ft_printf("Error\n");
	exit(error_code);
}

void	delete_words_of_numbers(char ***temp, int len)
{
	int	i;
	int	j;

	i = 0;
	while (++i < len)
	{
		j = 0;
		while (temp[i][j] != 0)
		{
			free(temp[i][j]);
			j++;
		}
		free(temp[i]);
	}
	free(temp);
}
