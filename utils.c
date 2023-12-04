#include "ft_printf.h"

int     ft_strlen(const char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}

void    parse_flags(const char **format, t_flags *flags, va_list args)
{
    while (**format == '-' || **format == '0' || **format == '.' || **format == '*' || ft_isdigit(**format) || **format == '#' || **format == ' ' || **format == '+')
    {
        if (**format == '-')
            flags->minus = 1;
        else if (**format == '0')
            flags->zero = 1;
        else if (**format == '.')
        {
            flags->dot = 0;
            (*format)++;
            if (**format == '*')
                flags->dot = va_arg(args, int);
            else
            {
                while (ft_isdigit(**format))
                    flags->dot = flags->dot * 10 + (*((*format)++) - '0');
                (*format)--;
            }
        }
        else if (**format == '*')
        {
            flags->width = va_arg(args, int);
            if (flags->width < 0)
            {
                flags->minus = 1;
                flags->width *= -1;
            }
        }
        else if (ft_isdigit(**format))
        {
            flags->width = 0;
            while (ft_isdigit(**format))
                flags->width = flags->width * 10 + (*((*format)++) - '0');
            (*format)--;
        }
        else if (**format == '#')
            flags->sharp = 1;
        else if (**format == ' ')
            flags->space = 1;
        else if (**format == '+')
            flags->plus = 1;

        (*format)++;
    }
}
