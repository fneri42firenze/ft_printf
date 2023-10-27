#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int 	ft_putnbr(int i);
int		ft_puthex_low (unsigned int num);
int		ft_puthex_up (unsigned int num);
#endif