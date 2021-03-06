/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knage <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 14:28:07 by knage             #+#    #+#             */
/*   Updated: 2016/07/07 07:26:35 by knage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# define BUFF_SIZE 10

typedef struct		s_c
{
	char	c;
	int		(*f)(va_list ap, int nb);
}					t_c;

char				*ft_strchr(const char *s, int c);
int					ft_atoi(const char *src);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memchr(const void *s1, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *s1);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_strlen(const char *s);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(char *str, char *to_find);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
char				**ft_strsplit(char const *s, char c);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
char				*ft_itoa(int n);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strmap(char const *s, char (*f)(char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
char				*ft_strnew(size_t size);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strtrim(const char *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_strdel(char **as);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
void				ft_strclr(char *s);
int					ft_strnqu(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_putstr(const char *s);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
int					ft_abs(int n);
int					ft_num_whitespaces(int *i, const char *format);
void				ft_print_whitespace(int n);
int					ft_putnbrl_pf(va_list ap, const char *format, int *i);
int					ft_putnbrll_pf(va_list ap, const char *format, int *i);
int					sft_putwchar(wchar_t *s);
int					ft_putnbr_base(long nb, const char *base);
int					ft_putnbr_base_u(unsigned int nb, const char *base);
int					ft_return_nb_nb(long nb, const char *base);
int					ft_return_nb_nb_di(int nb, const char *base);
int					ft_putnbr_pf(va_list ap, int nbb);
int					ft_putnbr_u_pf(va_list ap, int nbb);
int					ft_putchar_pf(va_list ap, int nbb);
int					ft_putstr_pf(va_list ap, int nbb);
int					ft_putoctal_pf(va_list ap, int nbb);
int					ft_putz_pf(va_list ap, const char *format, int *i);
int					ft_puthexa_min_pf(va_list ap, int nbb);
int					ft_puthexa_max_pf(va_list ap, int nbb);
int					ft_puthexa_pf(va_list ap, int nbb);
int					ft_printf(char const *str, ...);
int					ft_putwchar_pf(va_list ap, int nbb);
size_t				ft_wcslen(const wchar_t *ws);
int					ft_putwstr_pf(va_list ap, int nbb);
void				ft_putwstr(wchar_t *ws);
int                 get_next_line(const int fd, char **line);
long                ft_atoil(const char *str);
int					ft_isnbr(char c);
#endif
