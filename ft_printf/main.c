#include "ft_printf.h"

int     main()
{
	ft_printf("%11.s\n", "hello world");
	ft_printf("%5.sa\n", "hello world");
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