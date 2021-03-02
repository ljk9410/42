#include "ft_printf.h"

void	ft_putnum(char *str, int len)
{
	if (g_opts.minus == 1)
	{
		ft_putstr(str);
		print_space(len);
	}
	else
	{
		print_space(len);
		ft_putstr(str);
	}
}
