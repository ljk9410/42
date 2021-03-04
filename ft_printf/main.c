#include "ft_printf.h"

int     main()
{
	int n;
	
	n = 100;
//	ft_printf("%c\n", 'c');
//	ft_printf("%s\n", "hello world");
//	ft_printf("%*.*s\n", 15, 5, "hello world");
//	printf("%*.*s\n", 15, 5, "hello world");
//	ft_printf("%*.*%\n", 10, -5);
//	printf("%*.*%\n", 10, -5);
//	ft_printf("%15.11x\n", 123456);
//	printf("%15.11x\n", 123456);
	ft_printf("%u\n", 12345);
	printf("%u\n", 12345);
	ft_printf("%*p\n",30, &n);
	printf("%*p\n",30, &n);
	/*	printf("minus: %d zero: %d width_star: %d width: %d dot: %d precision: %d, no_precision: %d,  p_star: %d type: %c",
         g_opts.minus,
         g_opts.zero,
         g_opts.width_star,
         g_opts.width,
         g_opts.dot,
         g_opts.precision,
		 g_opts.no_precision,
         g_opts.precision_star,
         g_opts.type);
*/
    return (0);
}
