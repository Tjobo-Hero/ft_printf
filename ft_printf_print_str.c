/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_print_s_utils.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 16:07:06 by tvan-cit       #+#    #+#                */
/*   Updated: 2019/12/13 11:14:45 by tvan-cit      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	ft_putstring(char *s, t_list *data)
{
	int		i_s;

	if (!s)
		return ;
	i_s = 0;
	while (s[i_s] != '\0')
	{
		ft_putchar(s[i_s], data);
		i_s++;
	}
}

void	print_str_with_flags(t_list *data, char *arg)
{
	int		len;
	int		i_arg;

	i_arg = 0;
	len = ft_strlen(arg);
	if (data->has_precision && len > data->precision)
		len = data->precision;
	while (data->width > len && !data->flag_align)
	{
		ft_putchar(data->flag_zero, data);
		data->width--;
	}
	while (len > 0)
	{
		ft_putchar(arg[i_arg], data);
		len--;
		i_arg++;
		if (data->width != 0)
			data->width--;
	}
	while (data->flag_align && data->width > len)
	{
		ft_putchar(' ', data);
		data->width--;
	}
}

void	print_str(va_list ap, t_list *data)
{
	char *arg;

	arg = va_arg(ap, char*);
	if (arg == NULL)
		arg = "(null)";
	if (data->flag_align > 0 || data->width > 0 || data->has_precision)
		print_str_with_flags(data, arg);
	else
		ft_putstring(arg, data);
}
