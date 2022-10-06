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

static void	_ft_assign_num_or_exit(int *numbers, int len, char *strs[])
{
	static int	idx;
	int			i;

	if (strs == NULL)
	{
		idx = 0;
		return ;
	}
	i = 0;
	while (strs[i] != NULL)
	{
		if(is_valid_num(strs[i]))	
			numbers[idx++] = ft_atoi(strs[i]);
		else
		{
			ft_printf("Error\n");
			exit(-1);
		}
		++i;
	}
}

t_parsed_num	ps_parse(int ac, char *av[])
{
	int		ret;
	int		i;
	char	***temp;
	int		*numbers;

	ret = 0;
	i = 1;
	temp = malloc(sizeof(char **) * ac);
	while (i < ac)
	{
		temp[i] = ft_split(av[i], ' ');
		ret += _ft_strvlen(temp[i]);
		++i;
	}
	i = 1;
	numbers = malloc(sizeof(int) * (ret + 1));
	while (i < ac)
	{
		_ft_assign_num_or_exit(numbers, ret, temp[i]);
		++i;
	}
	return ((t_parsed_num){ret, numbers});
}

int	main(int ac, char *av[])
{
	int				i;
	t_parsed_num	numbers;

	if (ac < 1)
		return 0;
	numbers = ps_parse(ac, av);
	i = 0;
	while (i < numbers.len)
	{
		printf("%d\n", numbers.arr[i++]);
	}
}
