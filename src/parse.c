/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:30:57 by seonghyk          #+#    #+#             */
/*   Updated: 2022/10/24 14:07:02 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

static int	_ft_strvlen(char *av[])
{
	int	ret;

	ret = 0;
	while (av[ret] != NULL)
		++ret;
	return (ret);
}

static int	is_valid_num(char *str)
{
	int		i;
	long	ovflw_detection_l;
	int		ovflw_detection_i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(ft_isdigit(str[i]) || str[i] == '-'))
			return (0);
		++i;
	}
	ovflw_detection_l = ft_atoi_l(str);
	ovflw_detection_i = ovflw_detection_l;
	if (ovflw_detection_i != ovflw_detection_l || i > 11)
		return (0);
	return (1);
}

static int	_ft_assign_num(int *numbers, int num_idx, char *strs[])
{
	int	i;
	int	j;

	i = 0;
	while (strs[i] != NULL)
	{
		if (is_valid_num(strs[i]))
		{
			numbers[num_idx] = ft_atoi(strs[i]);
			j = num_idx;
			while (--j >= 0)
				if (numbers[j] == numbers[num_idx])
					return (-1);
		}
		else
			return (-1);
		++i;
		++num_idx;
	}
	return (num_idx);
}

int	_is_sorted(int *numbers, int len)
{
	int	prev;
	int	i;

	i = 1;
	prev = numbers[0];
	while (i < len)
	{
		if (numbers[i] < prev)
			return (0);
		prev = numbers[i];
		i++;
	}
	return (1);
}

t_parsed_num	ps_parse(int ac, char *av[])
{
	int		i;
	char	***temp;
	int		*numbers;
	int		num_idx;

	num_idx = 0;
	i = 0;
	temp = malloc(sizeof(char **) * ac);
	while (++i < ac)
	{
		temp[i] = ft_split(av[i], ' ');
		num_idx += _ft_strvlen(temp[i]);
	}
	numbers = malloc(sizeof(int) * (num_idx + 1));
	num_idx = 0;
	i = 0;
	while (++i < ac && num_idx != -1)
		num_idx = _ft_assign_num(numbers, num_idx, temp[i]);
	delete_words_of_numbers(temp, ac);
	if (num_idx == -1)
		exit_invalid_input(-1);
	if (_is_sorted(numbers, num_idx))
		exit(0);
	return ((t_parsed_num){num_idx, numbers});
}
