/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghyk <seonghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:43:39 by seonghyk          #+#    #+#             */
/*   Updated: 2022/10/05 17:27:32 by seonghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/* ctype */
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isascii(int c);
int			ft_isalnum(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

/* string */
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *s1, const char *s2, size_t n);
char		*ft_strdup(const char *str);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memcpy(void *s1, const void *s2, size_t n);
void		*ft_memmove(void *s1, const void *s2, size_t n);

/* strings */
void		ft_bzero(void *s, size_t n);

/* stdlib */
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);

/* Part2 */
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

struct	s_number_info {
	int		count;
	int		is_nag;
	char	*buf_digits;
};

# define INT_DIGITS_NUMBER 12

/* Bonus */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *n);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *n);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

char		*ft_itoa_base(int n, char *str, int base);
char		*ft_uitoa_base(unsigned int n, char *str, int base);
char		*ft_ultoa_base(unsigned long n, char *str, int base);

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

int			print_format_decimal(int fd, t_Format *format);
int			print_format_string(int fd, t_Format *format);
int			print_format_char(int fd, t_Format *format);
int			print_format_hex(int fd, t_Format *format);
int			print_format(int fd, t_Format *format);

int			ft_printf(const char *format, ...);
int			ft_vdprintf(int fd, const char *format, va_list ap);

#endif
