#include "ft_printf.h"

int     main()
{
    ft_printf("hello %-000012345.6789d world\n");
    printf("minus: %d zero: %d width_star: %d width: %d dot: %d precision: %d p_star: %d type: %c",
        g_opts.minus,
        g_opts.zero,
        g_opts.width_star,
        g_opts.width,
        g_opts.dot,
        g_opts.precision,
        g_opts.precision_star,
        g_opts.type);
    return (0);
}