/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_struct_utils.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 12:12:07 by tvan-cit       #+#    #+#                */
/*   Updated: 2019/12/17 17:00:41 by tvan-cit      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	make_empty_struct(t_list *data)
{
	data->flag_align = 0;
	data->flag_zero = ' ';
	data->precision = 0;
	data->has_precision = 0;
	data->width = 0;
	data->size = 0;
	data->type = 0;
	data->count = 0;
	data->is_neg = 0;
	data->len = 0;
	data->put_hex = 0;
}

void	clear_data(t_list *data)
{
	data->flag_align = 0;
	data->flag_zero = ' ';
	data->precision = 0;
	data->has_precision = 0;
	data->width = 0;
	data->size = 0;
	data->type = 0;
	data->is_neg = 0;
	data->len = 0;
	data->put_hex = 0;
}

void	collect_all_struct_data(const char **str,
va_list ap, t_list *data)
{
	clear_data(data);
	look_for_flags(str, data, ap);
	look_for_type(str, data, ap);
}
