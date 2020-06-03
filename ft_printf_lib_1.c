/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_lib.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-cit <tvan-cit@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 09:51:37 by tvan-cit       #+#    #+#                */
/*   Updated: 2019/12/16 11:18:30 by tvan-cit      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = NULL;
	while (*s)
	{
		if (*s == c)
		{
			ptr = (char*)s;
			return (ptr);
		}
		s++;
	}
	if (c == '\0')
		return ((char*)s);
	return (ptr);
}

static long int		ft_convert(const char *str, int i,
unsigned long int result, int sign)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((result >= 922337203685477580 && (str[i] - '0') > 7) && sign == 1)
			return (-1);
		else if ((result >= 922337203685477580 && (str[i] - '0') > 8)
		&& sign == -1)
			return (0);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int					ft_atoi(const char *str)
{
	unsigned long int	result;
	int					i;
	int					sign;

	result = 0;
	i = 0;
	sign = 1;
	while (str[i] != '\0' && (str[i] == ' ' || (8 < str[i] && str[i] < 14)))
		i++;
	if ((str[i] == '+' && str[i + 1] == '-') ||
	(str[i] == '-' && str[i + 1] == '+'))
		return (0);
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
		if (str[i] == '+')
			return (0);
	}
	result = ft_convert(str, i, result, sign);
	return ((int)result * sign);
}

int					ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int					ft_number_count(int n, t_list *data)
{
	int		numbercount;

	if (n < 0)
		data->is_neg = 1;
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
