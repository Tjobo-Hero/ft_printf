/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_print_digit.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 11:46:30 by tvan-cit       #+#    #+#                */
/*   Updated: 2019/12/19 10:45:13 by tvan-cit      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			precision_counter(int arg, t_list *data)
{
	int	p_counter;
	int len;

	p_counter = 0;
	len = ft_number_count(arg, data);
	if (data->precision == 0)
		return (0);
	if (data->precision > len)
	{
		p_counter = data->precision;
		if (arg < 0)
			p_counter++;
	}
	if (data->precision == len)
	{
		p_counter = data->precision;
		if (arg < 0)
			p_counter++;
	}
	if (len > data->precision)
		p_counter = len;
	return (p_counter);
}

void		print_digit_with_precision_and_width(int arg, t_list *data)
{
	int		len;
	int		p_counter;

	len = ft_number_count(arg, data);
	p_counter = precision_counter(arg, data);
	if (data->flag_align)
	{
		if (p_counter != 0)
			print_digit_with_precision(arg, data);
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
			print_digit_with_precision(arg, data);
	}
}

void		print_digit_with_precision(int arg, t_list *data)
{
	int		len;

	len = ft_number_count(arg, data);
	if (data->is_neg && data->precision >= len)
	{
		ft_putchar('-', data);
		arg = arg * -1;
		data->precision++;
	}
	while (data->precision > len)
	{
		ft_putchar('0', data);
		data->precision--;
	}
	if (data->precision != 0)
		ft_putnbr(arg, data);
}

void		print_digit_with_width(int arg, t_list *data)
{
	int		len;

	len = ft_number_count(arg, data);
	if (data->is_neg && data->width > len && data->flag_zero == '0')
	{
		ft_putchar('-', data);
		arg = arg * -1;
	}
	while (data->width > len && !data->flag_align)
	{
		ft_putchar(data->flag_zero, data);
		data->width--;
	}
	ft_putnbr(arg, data);
	while (data->flag_align && data->width > len)
	{
		ft_putchar(' ', data);
		data->width--;
	}
}

void		print_digit(va_list ap, t_list *data)
{
	int arg;

	arg = va_arg(ap, int);
	if (data->width && !data->has_precision)
		print_digit_with_width(arg, data);
	else if (!data->width && data->has_precision)
		print_digit_with_precision(arg, data);
	else if (data->width && data->has_precision)
		print_digit_with_precision_and_width(arg, data);
	else
		ft_putnbr(arg, data);
}
