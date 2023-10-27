#include "ft_printf.h"

int	ft_putnbr(int i)
{
	if(i == 0)
		ft_putchar('0');
	else if (i == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if(i < 0)
		{
			ft_putchar('-');
			i = -i;
		}
		if(i / 10 != 0)
			ft_putnbr(i / 10);
		ft_putchar(i % 10 + '0');
	}
	return (1);
}

int ft_puthex_low(unsigned int num) 
{
	int i;
	char num_hex_low;
	int rest;

	i = 0;
	if (num == 0) {
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

int ft_puthex_up(unsigned int num) 
{
	int i;
	char num_hex_low;
	int rest;

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
			num_hex_low = rest + 'A' - 10;
		ft_putchar(num_hex_low);
		num /= 16;
		i++;
	}
	return (i);
}