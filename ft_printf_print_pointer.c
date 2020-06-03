/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_print_pointer.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 17:30:45 by tvan-cit       #+#    #+#                */
/*   Updated: 2019/12/18 16:00:31 by tvan-cit      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_pointer_prefix(t_list *data)
{
	ft_putchar('0', data);
	ft_putchar('x', data);
}

void		print_pointer_exception(t_list *data)
{
	while (data->width > data->len && !data->flag_align)
	{
		ft_putchar(data->flag_zero, data);
		data->width--;
	}
	print_pointer_prefix(data);
	while (data->flag_align && data->width > data->len)
	{
		ft_putchar(' ', data);
		data->width--;
	}
}

void		print_pointer_with_flags(t_list *data, unsigned long arg)
{
	while (data->width > data->len && !data->flag_align)
	{
		ft_putchar(data->flag_zero, data);
		data->width--;
	}
	print_pointer_prefix(data);
	ft_puthex(arg, data);
	while (data->flag_align && data->width > data->len)
	{
		ft_putchar(' ', data);
		data->width--;
	}
}

void		print_pointer(va_list ap, t_list *data)
{
	unsigned long arg;

	data->put_hex = 96;
	arg = va_arg(ap, unsigned long);
	ft_hex_count(arg, data);
	data->len = data->len + 2;
	if (arg == 0 && data->has_precision)
	{
		data->len = data->len - 1;
		print_pointer_exception(data);
	}
	else if (data->flag_align || data->width || data->has_precision)
		print_pointer_with_flags(data, arg);
	else
	{
		print_pointer_prefix(data);
		ft_puthex(arg, data);
	}
}
