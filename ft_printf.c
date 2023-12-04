#include "ft_printf.h"

int     ft_printf(const char *format, ...)
{
    va_list args;
    t_flags flags;

    va_start(args, format);
    int count = 0;

    while (*format)
    {
        if (*format == '%' && *(format + 1))
        {
            format++;
            parse_flags(&format, &flags, args);
            if (*format)
            {
                if (*format == 'c')
                    conversion_c(args, &flags);
                else if (*format == 's')
                    conversion_s(args, &flags);
                else if (*format == 'p')
                    conversion_p(args, &flags);
                else if (*format == 'd' || *format == 'i')
                    conversion_di(args, &flags);
                else if (*format == 'u')
                    conversion_u(args, &flags);
                else if (*format == 'x')
                    conversion_x(args, &flags, 0);
                else if (*format == 'X')
                    conversion_x(args, &flags, 1);
                else if (*format == '%')
                    conversion_percent(&flags);
            }
        }
        else
        {
            write(1, format, 1);
            count++;
        }
        format++;
    }

    va_end(args);
    return (count);
}
