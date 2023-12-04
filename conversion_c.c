#include "ft_printf.h"

void    conversion_c(va_list args, t_flags *flags)
{
    char c = (char)va_arg(args, int);

    if (flags->minus)
    {
        write(1, &c, 1);
        while (--(flags->width) > 0)
            write(1, " ", 1);
    }
    else
    {
        while (--(flags->width) > 0)
            write(1, " ", 1);
        write(1, &c, 1);
    }
}
