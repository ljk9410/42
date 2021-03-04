#include "ft_printf.h"

void			ft_putnum(char *str, int len)
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

static void		print_zero(int len)
{
	int i;
	i = 0;
	while (i < len)
	{
		write(1, "0", 1);
		g_opts.result++;
		i++;
	}
}

void			ft_putnum_width(char *str, int len)
{
	if (g_opts.minus == 1)
		ft_putnum(str, len);
	if (g_opts.minus == 0)
	{
		if (g_opts.zero == 0)
			ft_putnum(str, len);
		else
		{
			if (str[0] == '-')
			{
				write(1, &str[0], 1);
				g_opts.result++;
				str++;
			}
			print_zero(g_opts.width - len);
			ft_putstr(str);
		}
	}
}

void			ft_putnum_wp(char *str, int len)
{
	if (g_opts.precision >= g_opts.width)
	{
		print_zero(g_opts.precision - len);
		ft_putstr(str);
	}
	else
	{
		if (g_opts.minus == 1)
		{
			print_zero(g_opts.precision - len);
			ft_putstr(str);
			print_space(g_opts.precision);
		}
		else
		{
			print_space(g_opts.precision);
			print_zero(g_opts.precision - len);
			ft_putstr(str);
		}
	}
}

void			ft_putnum_wp_minus(char *str, int len)
{
	str++;
	if ((g_opts.precision + 1) >= g_opts.width)
	{
		write(1, "-", 1);
		print_zero(g_opts.precision - len + 1);
		ft_putstr(str);
	}
	else
	{
		if (g_opts.minus == 1)
		{
			write(1, "-", 1);
			print_zero(g_opts.precision - len + 1);
			ft_putstr(str);
			print_space(g_opts.precision + 1);
		}
		else
		{
			print_space(g_opts.precision + 1);
			write(1, "-", 1);
			print_zero(g_opts.precision - len + 1);
			ft_putstr(str);
		}
	}
	g_opts.result++;
}
