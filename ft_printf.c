/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 15:18:02 by tvan-cit       #+#    #+#                */
/*   Updated: 2019/12/19 10:51:07 by tvan-cit      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_printf(const char *str, ...)
{
	va_list ap;
	t_list	data;

	make_empty_struct(&data);
	va_start(ap, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			collect_all_struct_data(&str, ap, &data);
		}
		if (*str != '\0' && *str != '%')
		{
			ft_putchar(str[0], &data);
			str++;
		}
	}
	va_end(ap);
	return (data.count);
}
