/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:30:12 by seonghyk          #+#    #+#             */
/*   Updated: 2022/10/24 13:58:24 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

typedef struct s_parsed_num {
	int	len;
	int	*arr;
}	t_parsed_num;

long			ft_atoi_l(const char *str);
t_parsed_num	ps_parse(int ac, char *av[]);
void			exit_invalid_input(int error_code);
void			delete_words_of_numbers(char ***temp, int len);

#endif
