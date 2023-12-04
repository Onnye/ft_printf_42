#include "ft_printf.h"

void    conversion_s(va_list args, t_flags *flags)
{
    char *str = va_arg(args, char*);

    if (!str)
        str = "(null)";

    int len = 0;
    while (str[len])
        len++;

    if (flags->dot && flags->width > flags->dot && flags->dot < len)
        len = flags->dot;

    if (flags->minus)
    {
        write(1, str, len);
        while (--(flags->width) > len)
            write(1, " ", 1);
    }
    else
    {
        while (--(flags->width) > len)
            write(1, " ", 1);
        write(1, str, len);
    }
}
