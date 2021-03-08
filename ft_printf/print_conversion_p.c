#include "ft_printf.h"

static void		print_output(char *str)
{
	int			len;

	len = ft_strlen(str);
	if (g_opts.minus == 0)
	{
		print_space(len + 2);
		write(1, "0", 1);
		write(1, "x", 1);
		ft_putstr(str);
	}
	else
	{
		write(1, "0", 1);
		write(1, "x", 1);
		ft_putstr(str);
		print_space(len + 2);
	}
	g_opts.result += 2;
}

static void		print_output_null(char *str)
{
	if (g_opts.width <= 3)
	{
		write(1, "0", 1);
		write(1, "x", 1);
		ft_putstr(str);
	}
	else
	{
		print_output(str);
		g_opts.result -= 2;
	}
}

static void		print_output_nofit(char *str)
{
	if (ft_strlen(str) == 1)
		print_output_null(str);
	else
	{
		write(1, "0", 1);
		write(1, "x", 1);
		ft_putstr(str);
	}
	g_opts.result += 2;
}

void			print_conversion_p(va_list ap)
{
	long long	ptr;
	char		*ptr_str;

	handle_wp_star(ap);
	ptr = va_arg(ap, long long);
	ptr_str = ft_itoa_base(ptr, 16, 'x');
	if (g_opts.width < 14)
		print_output_nofit(ptr_str);
	else
		print_output(ptr_str);
	free(ptr_str);
}
