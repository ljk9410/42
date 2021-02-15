#include "ft_printf.h"

int     main()
{
    ft_printf("This is %c", 'A');
    write(1, "\n", 1);
    return (0);
}