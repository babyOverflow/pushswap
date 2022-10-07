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

static int	_ft_assign_num(int *numbers, int len, char *strs[])
{
	int	i;
	int	j;

	i = 0;
	while (strs[i] != NULL)
	{
		if(is_valid_num(strs[i]))	
		{
			numbers[i] = ft_atoi(strs[i]);
			j = i;
			while (--j >= 0)
				if (numbers[j] == numbers[i])
					return (-1);
		}
		else
			return (-1);
		++i;
	}
	return (1);
}

t_parsed_num	ps_parse(int ac, char *av[])
{
	int		ret;
	int		i;
	char	***temp;
	int		*numbers;
	int		check_num;

	ret = 0;
	i = 1;
	temp = malloc(sizeof(char **) * ac);
	while (i < ac)
	{
		temp[i] = ft_split(av[i], ' ');
		ret += _ft_strvlen(temp[i]);
		++i;
	}
	numbers = malloc(sizeof(int) * (ret + 1));
	check_num = 1;
	i = 0;
	while (++i < ac && check_num == 1)
		check_num = _ft_assign_num(numbers, ret, temp[i]);
	if (check_num == -1)
	{
		ft_printf("Error\n");
		exit(-1);
	}
	return ((t_parsed_num){ret, numbers});
}
