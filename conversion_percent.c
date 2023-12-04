#include "ft_printf.h"

void    conversion_percent(t_flags *flags)
{
    if (flags->minus)
    {
        write(1, "%", 1);
        while (--(flags->width) > 0)
            write(1, " ", 1);
    }
    else
    {
        while (--(flags->width) > 0)
            write(1, flags->zero ? "0" : " ", 1);
        
        write(1, "%", 1);
    }
}
