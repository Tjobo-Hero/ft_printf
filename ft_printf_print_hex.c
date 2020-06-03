/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_print_hex.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 12:08:09 by tvan-cit       #+#    #+#                */
/*   Updated: 2019/12/18 17:11:59 by tvan-cit      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			hex_precision_counter(t_list *data)
{
	int	p_counter;

	p_counter = 0;
	if (data->precision == 0)
		return (0);
	if (data->precision > data->len)
		p_counter = data->precision;
	if (data->precision == data->len)
		p_counter = data->precision;
	if (data->len > data->precision)
		p_counter = data->len;
	return (p_counter);
}

void		print_hex_with_precision_and_width(unsigned long arg, t_list *data)
{
	int		p_counter;

	p_counter = hex_precision_counter(data);
	if (data->flag_align)
	{
		if (p_counter != 0)
			print_hex_with_precision(arg, data);
		while (data->width > p_counter)
		{
			ft_putchar(' ', data);
			data->width--;
		}
	}
	else
	{
		while (data->width > p_counter)
		{
			ft_putchar(' ', data);
			data->width--;
		}
		if (p_counter != 0)
			print_hex_with_precision(arg, data);
	}
}

void		print_hex_with_precision(unsigned long arg, t_list *data)
{
	while (data->precision > data->len)
	{
		ft_putchar('0', data);
		data->precision--;
	}
	if (data->precision != 0)
		ft_puthex(arg, data);
}

void		print_hex_with_width(unsigned long arg, t_list *data)
{
	while (data->width > data->len && !data->flag_align)
	{
		ft_putchar(data->flag_zero, data);
		data->width--;
	}
	ft_puthex(arg, data);
	while (data->flag_align && data->width > data->len)
	{
		ft_putchar(' ', data);
		data->width--;
	}
}

void		print_hex(va_list ap, t_list *data)
{
	unsigned long arg;

	arg = va_arg(ap, unsigned int);
	ft_hex_count(arg, data);
	if (data->width && !data->has_precision)
		print_hex_with_width(arg, data);
	else if (!data->width && data->has_precision)
		print_hex_with_precision(arg, data);
	else if (data->width && data->has_precision)
		print_hex_with_precision_and_width(arg, data);
	else
		ft_puthex(arg, data);
}
