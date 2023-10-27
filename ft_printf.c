/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fneri <fneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:07:33 by fneri             #+#    #+#             */
/*   Updated: 2023/10/27 12:10:47 by fneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_invert(char *array)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = ft_strlen(array) - 1;
	while (i < j)
	{
		if (array[i] == '-')
			i++;
		else
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	}
	ft_putstr((char *)array);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	select_format(va_list arguments, const char in)
{
	int	printable;

	printable = 0;
	if (in == 'c')
		printable = ft_putchar(va_arg(arguments, int));
	if (in == 's')
		printable = ft_putstr(va_arg(arguments, char *));
	if (in == 'p')
		printable = ft_pointer_puthex(va_arg(arguments, void *));
	if (in == 'd' || in == 'i')
		printable = ft_putnbr(va_arg(arguments, int));
	if (in == 'u')
		printable = ft_putnbr(va_arg(arguments, unsigned int));
	if (in == 'x')
		printable = ft_puthex_low(va_arg(arguments, unsigned int));
	if (in == 'X')
		printable = ft_puthex_up(va_arg(arguments, unsigned int));
	if (in == '%')
		printable = ft_putchar('%');
	return (printable);
}

int	ft_printf(const char *in, ...)
{
	int		i;
	int		printable;
	va_list	arguments;

	if (!in)
		return (0);
	i = 0;
	printable = 0;
	va_start(arguments, in);
	while (in[i])
	{
		if (in[i] == '%')
		{
			printable += select_format(arguments, in[i + 1]);
			i++;
		}
		else
			printable += ft_putchar(in[i]);
		i++;
	}
	va_end(arguments);
	return (printable);
}

// int main()
// {
// 	// char c;
// 	// c = 'c';
// 	// char *str;
// 	// str = "Hello World!";
// 	printf("%i\n", ft_printf("LA STRINGA E' %d\n", -101));
// 	printf("%i\n", printf("LA STRINGA E' %d\n", -101));
// 	// int i;
// 	// 	i = 255;
// 	// 	ft_printf("LA STRINGA E' %X\n", i);
// }
