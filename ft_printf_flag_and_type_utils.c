/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_flag_and_type_utils.c                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 11:39:30 by tvan-cit       #+#    #+#                */
/*   Updated: 2019/12/18 17:36:13 by tvan-cit      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	look_for_precision(const char **str, t_list *data, va_list ap)
{
	if (**str == '.')
	{
		if (((*str)[1] >= '0' && (*str)[1] <= '9') || (*str)[1] == '*')
			(*str)++;
		data->has_precision = 1;
		if (**str == '*')
			data->precision = va_arg(ap, int);
		if (data->precision < 0)
		{
			data->precision = 0;
			data->has_precision = 0;
		}
		if ('0' <= **str && **str <= '9')
			data->precision = ft_atoi(*str);
		while ('0' <= (*str)[1] && (*str)[1] <= '9')
			(*str)++;
	}
}

void	look_for_width(const char **str, t_list *data)
{
	if ('0' <= **str && **str <= '9')
	{
		data->width = ft_atoi(*str);
		while ('0' <= (*str)[1] && (*str)[1] <= '9')
			(*str)++;
	}
}

void	look_for_flags(const char **str, t_list *data, va_list ap)
{
	while ((ft_strchr("cspd%iuxX", (int)(*str)[0]) == NULL))
	{
		if (**str == '-')
			data->flag_align = 1;
		else if (**str == '0')
			data->flag_zero = '0';
		else if (**str == '*')
			data->width = va_arg(ap, int);
		if (data->width < 0)
		{
			data->width = data->width * -1;
			data->flag_align = 1;
		}
		look_for_width(str, data);
		look_for_precision(str, data, ap);
		(*str)++;
	}
}

void	look_for_type(const char **str, t_list *data, va_list ap)
{
	if (**str == 'c')
		print_c(ap, data);
	else if (**str == '%')
		print_percentage(data);
	else if (**str == 's')
		print_str(ap, data);
	else if (**str == 'd')
		print_digit(ap, data);
	else if (**str == 'p')
		print_pointer(ap, data);
	else if (**str == 'i')
		print_digit(ap, data);
	else if (**str == 'u')
		print_unsigned_int(ap, data);
	else if (**str == 'x')
	{
		data->put_hex = 96;
		print_hex(ap, data);
	}
	else if (**str == 'X')
	{
		data->put_hex = 64;
		print_hex(ap, data);
	}
	(*str)++;
}
