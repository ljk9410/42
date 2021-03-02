#include "ft_printf.h"

int     main()
{
//	ft_printf("%c\n", 'c');
//	ft_printf("%s\n", "hello world");
//	ft_printf("%*.*s\n", 15, 5, "hello world");
//	printf("%*.*s\n", 15, 5, "hello world");
//	ft_printf("%*.*%\n", 10, -5);
//	ft_printf("%*.*d\n", -10, 5, -123456);
	ft_printf("%0*.*d\n", -15, 10, -12345);
	printf("%0*.*d\n", -15, 10, -12345);
	printf("minus: %d zero: %d width_star: %d width: %d dot: %d precision: %d, no_precision: %d,  p_star: %d type: %c",
         g_opts.minus,
         g_opts.zero,
         g_opts.width_star,
         g_opts.width,
         g_opts.dot,
         g_opts.precision,
		 g_opts.no_precision,
         g_opts.precision_star,
         g_opts.type);

    return (0);
}
