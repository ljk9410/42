#include <stdio.h>
#include "ft_printf.h"

int 	main()
{
	int *ptr = 0;

	if ((void *)ptr == NULL)
		printf("hello");
	ft_printf("%.p\n", NULL);
	ft_printf("%p\n", NULL);
	return (0);
}
