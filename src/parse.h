typedef struct s_parsed_num {
	int	len;
	int	*arr;
}	t_parsed_num;

long			ft_atoi_l(const char *str);
t_parsed_num	ps_parse(int ac, char *av[]);