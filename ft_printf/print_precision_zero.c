#include "ft_printf.h"

void	print_precision_zero(void)
{
	int len;

	len = 0;
	if (g_opts.width > 0)
		len = g_opts.width;
	while (len)
	{
		write(1, " ", 1);
		g_opts.result++;
		len--;
	}
}
