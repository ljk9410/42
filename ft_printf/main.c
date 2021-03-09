#include <stdio.h>
#include "ft_printf.h"

int 	main()
{
	printf("%9.2p\n", 1234);
	ft_printf("%.p\n", NULL);
	printf("%2.9p\n", 1234);
	ft_printf("%p\n", NULL);
	printf("%.5p", 0);
	return (0);
}
