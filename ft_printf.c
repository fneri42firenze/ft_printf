/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fneri <fneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:07:33 by fneri             #+#    #+#             */
/*   Updated: 2023/10/25 21:41:38 by fneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int select_format(va_list arguments, const char in)
{
	int	printable;

	printable = 0;
	if (in == 'c')
		printable = ft_putchar(va_arg(arguments, int));
	// if (in == 's')
	// 	printable = ft_putstr(va_arg(arguments, char *));
	// if (in == 'p')
	// 	printable = ft_putpointerhex(va_arg(arguments, unsigned long long));
	// if (in == 'd' || in == 'i')
	// 	printable = ft_putnbr(va_arg(arguments, int));
	// if (in == 'u')
	// 	printable = ft_putnbr(va_arg(arguments, unsigned int));
	// if (in == 'x' || in == 'X')
	// 	printable = ft_puthex(va_arg(arguments, unsigned int));
	if (in == '%')
		printable = ft_putchar('%');
	return (printable);
}

int	ft_printf(const char *in, ...)
{
	int	i;
	int	printable;
	va_list	arguments;
	
	if(!in)
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
			printable = ft_putchar(in[i]);
		i++;
	}
	va_end(arguments);
	return (printable);
}

int main()
{
	// char c;
	// c = 'c';
	ft_printf("Hello %%");
}