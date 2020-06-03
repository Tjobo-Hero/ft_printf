/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 10:15:28 by tvan-cit       #+#    #+#                */
/*   Updated: 2019/12/19 11:05:44 by tvan-cit      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	int		flag_align;
	char	flag_zero;
	int		width;
	int		precision;
	int		has_precision;
	int		is_neg;
	int		size;
	int		type;
	int		count;
	int		len;
	int		put_hex;
}				t_list;

int				ft_printf(const char *str, ...);
char			*ft_strchr(const char *s, int c);
void			ft_putchar(char c, t_list *data);
int				ft_atoi(const char *str);
char			*ft_strchr(const char *s, int c);
int				ft_strlen(char *s);
void			ft_putstring(char *s, t_list *data);
void			ft_putnbr(int n, t_list *data);
int				ft_number_count(int n, t_list *data);
void			ft_puthex(unsigned long n, t_list *data);
void			ft_puthex_capital(unsigned long n, t_list *data);
int				ft_hex_count(unsigned long arg, t_list *data);
void			ft_putnbr_unsigned_int(unsigned int n, t_list *data);
int				ft_number_count_unsigned_int(unsigned int n);
void			collect_all_struct_data(const char **str,
va_list ap, t_list *data);
void			make_empty_struct(t_list *data);
void			clear_data(t_list *data);
void			look_for_type(const char **str, t_list *data, va_list ap);
void			look_for_flags(const char **str, t_list *data, va_list ap);
void			look_for_width(const char **str, t_list *data);
void			look_for_precision(const char **str, t_list *data, va_list ap);
void			print_c(va_list ap, t_list *data);
void			print_c_with_flags(va_list ap, t_list *data);
void			print_percentage(t_list *data);
void			print_percentage_with_flags(t_list *data);
void			print_str(va_list ap, t_list *data);
void			print_str_with_flags(t_list *data, char *arg);
void			print_digit(va_list ap, t_list *data);
void			print_digit_with_width(int arg, t_list *data);
void			print_digit_with_precision(int arg, t_list *data);
void			print_digit_with_precision_and_width(int arg, t_list *data);
int				precision_counter(int arg, t_list *data);
void			print_hex(va_list ap, t_list *data);
void			print_hex_with_width(unsigned long arg, t_list *data);
void			print_hex_with_precision(unsigned long arg, t_list *data);
void			print_hex_with_precision_and_width(unsigned long arg,
t_list *data);
int				hex_precision_counter(t_list *data);
void			print_pointer(va_list ap, t_list *data);
void			print_pointer_prefix(t_list *data);
void			print_pointer_with_flags(t_list *data, unsigned long arg);
void			print_unsigned_int(va_list ap, t_list *data);
int				precision_counter_unsigned_int(unsigned int arg, t_list *data);
void			print_unsigned_int_with_precision_and_width(unsigned int arg,
t_list *data);
void			print_unsigned_int_with_precision(unsigned int arg,
t_list *data);
void			print_unsigned_int_with_width(unsigned int arg, t_list *data);
#endif
