/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_lib_2.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 13:48:53 by tvan-cit       #+#    #+#                */
/*   Updated: 2019/12/18 12:36:34 by tvan-cit      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putnbr(int n, t_list *data)
{
	char c;

	if (n < 0)
	{
		ft_putchar('-', data);
		if (n == -2147483648)
		{
			ft_putnbr(214748364, data);
			ft_putnbr(8, data);
			return ;
		}
		else
			n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, data);
		ft_putnbr(n % 10, data);
	}
	else
	{
		c = n + 48;
		ft_putchar(c, data);
	}
}

int			ft_hex_count(unsigned long arg, t_list *data)
{
	if (arg >= 16)
	{
		ft_hex_count(arg / 16, data);
		ft_hex_count(arg % 16, data);
	}
	else
		data->len++;
	return (data->len);
}

void		ft_puthex(unsigned long n, t_list *data)
{
	int i;

	i = 0;
	if (n >= 16)
	{
		ft_puthex(n / 16, data);
		ft_puthex(n % 16, data);
	}
	else if (n <= 9)
	{
		n = n + 48;
		ft_putchar(n, data);
	}
	else
	{
		while (n >= 10)
		{
			i++;
			n--;
		}
		ft_putchar(data->put_hex + i, data);
		i = 0;
	}
}

void		ft_putnbr_unsigned_int(unsigned int n, t_list *data)
{
	char c;

	if (n >= 10)
	{
		ft_putnbr(n / 10, data);
		ft_putnbr(n % 10, data);
	}
	else
	{
		c = n + 48;
		ft_putchar(c, data);
	}
}

int			ft_number_count_unsigned_int(unsigned int n)
{
	int		numbercount;

	numbercount = 0;
	if (n == 0 || n == -0)
		return (1);
	if (n < 0)
	{
		numbercount++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		numbercount++;
	}
	return (numbercount);
}
