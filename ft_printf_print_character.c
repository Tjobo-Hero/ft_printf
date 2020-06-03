/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_print_c_utils.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 14:02:46 by tvan-cit       #+#    #+#                */
/*   Updated: 2019/12/13 10:38:43 by tvan-cit      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_list *data)
{
	write(1, &c, 1);
	data->count += 1;
}

void	print_c_with_flags(va_list ap, t_list *data)
{
	int		index;
	char	argument;

	index = 1;
	argument = va_arg(ap, int);
	if (data->flag_align > 0)
	{
		ft_putchar(argument, data);
		while (data->width > index)
		{
			ft_putchar(' ', data);
			index++;
		}
	}
	if (data->width > 0 && data->flag_align == 0)
	{
		while (data->width > index)
		{
			ft_putchar(data->flag_zero, data);
			index++;
		}
		ft_putchar(argument, data);
	}
}

void	print_c(va_list ap, t_list *data)
{
	char argument;

	if (data->flag_align > 0 || data->width > 0)
		print_c_with_flags(ap, data);
	else
	{
		argument = va_arg(ap, int);
		ft_putchar(argument, data);
	}
}
