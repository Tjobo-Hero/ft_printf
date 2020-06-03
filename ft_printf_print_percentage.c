/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_print_percentage_utils.c                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 10:31:30 by tvan-cit       #+#    #+#                */
/*   Updated: 2019/12/12 10:32:05 by tvan-cit      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percentage_with_flags(t_list *data)
{
	int		index;

	index = 1;
	if (data->flag_align > 0)
	{
		ft_putchar('%', data);
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
		ft_putchar('%', data);
	}
}

void	print_percentage(t_list *data)
{
	if (data->flag_align > 0 || data->width > 0)
		print_percentage_with_flags(data);
	else
		ft_putchar('%', data);
}
