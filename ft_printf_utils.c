/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fneri <fneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 08:47:28 by fneri             #+#    #+#             */
/*   Updated: 2023/10/27 13:31:54 by fneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int	ft_putnbr(long i)
{
	int		count;
	char	array[30];

	count = 0;
	if (i == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (i < 0)
	{
		array[count] = '-';
		i = -i;
		count++;
	}
	while (i >= 10)
	{
		array[count] = ((i % 10) + '0');
		i = i / 10;
		count ++;
	}
	array[count] = (i + '0');
	array[count + 1] = '\0';
	ft_invert((char *)array);
	return (count + 1);
}

int	ft_puthex_low(unsigned int num)
{
	char	num_hex_low[30];
	int		count;

	count = 0;
	if (num == 0)
		num_hex_low[count] = '0';
	while (num > 10)
	{
		if((num % 16) < 10)
			num_hex_low[count] = ((num % 16) + '0');
		else
			num_hex_low[count] = ((num % 16) + 'a' - 10);
		num /= 16;
		count++;
	}
	while(num > 0)
	{
		num_hex_low[count] = ((num % 16) + '0');
		num /= 16;
	}
	num_hex_low[count + 1] = '\0';
	ft_invert((char *)num_hex_low);
	return (count + 1);
}

int	ft_puthex_up(unsigned int num)
{
	char	num_hex_up[30];
	int		count;

	count = 0;
	if (num == 0)
		num_hex_up[count] = '0';
	while (num > 10)
	{
		if((num % 16) < 10)
			num_hex_up[count] = ((num % 16) + '0');
		else
			num_hex_up[count] = ((num % 16) + 'a' - 10);
		num /= 16;
		count++;
	}
	while(num > 0)
	{
		num_hex_up[count] = ((num % 16) + '0');
		num /= 16;
	}
	num_hex_up[count + 1] = '\0';
	ft_invert((char *)num_hex_up);
	return (count + 1);
}

int	ft_pointer_puthex(void *ptr)
{
	unsigned long long	num;
	int					i;
	char				num_hex_low;
	int					rest;

	num = (unsigned long long)ptr;
	i = 0;
	if (num == 0)
	{
		ft_putchar('0');
		return (1);
	}
	while (num > 0)
	{
		rest = num % 16;
		if (rest < 10)
			num_hex_low = rest + '0';
		else
			num_hex_low = rest + 'a' - 10;
		ft_putchar(num_hex_low);
		num /= 16;
		i++;
	}
	return (i);
}
