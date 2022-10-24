/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_format.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:32:49 by seonghyk          #+#    #+#             */
/*   Updated: 2022/06/10 20:45:13 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FORMAT_H
# define T_FORMAT_H

enum e_varg_flag {
	FMT_ALTER_FORM = (0x01 << 0),
	FMT_ZERO_PADDING = (0x01 << 1),
	FMT_NEG_FILED = (0x01 << 2),
	FMT_BLANK_PADDING = (0x01 << 3),
	FMT_SIGN_ALWAYS = (0x01 << 4),
};

typedef union u_FmtValue {
	char			as_char;
	int				as_int;
	unsigned int	as_uint;
	long			as_ulong;
	void			*as_pointer;
}	t_FmtValue;

typedef struct s_Prefix {
	int		len;
	char	*str;
}	t_Prefix;

typedef struct s_Format {
	char				type_c;
	enum e_varg_flag	flags;
	int					is_valid;
	int					padding;
	int					precision;
	int					offset;
	t_FmtValue			value;
}	t_Format;

int			hexadecimal_to_string(unsigned long p, char *buf, int options);
int			unsigned_decimal_to_string(unsigned int d, char *buf);
int			decimal_to_string(int d, char *buf);
int			chr_to_string(char c, char *buf);

void		t_format_set_arg_int(t_Format *format, int arg);
void		t_format_set_arg_uint(t_Format *format, unsigned int arg);
void		t_format_set_arg_pointer(t_Format *format, void *arg);
t_Format	t_format_create(char *fmt, va_list ap);

#endif