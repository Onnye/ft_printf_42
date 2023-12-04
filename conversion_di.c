#include "ft_printf.h"

void    conversion_di(va_list args, t_flags *flags)
{
    int num = va_arg(args, int);

    int len = 0;
    int temp = num;

    if (num < 0)
    {
        len++;
        temp = -num;
    }

    while (temp > 0)
    {
        temp /= 10;
        len++;
    }

    if (num == 0 && flags->dot == 0)
        len = 0;

    if (flags->dot > len)
        len = flags->dot;

    char *str = (char *)malloc(len + 1);
    str[len] = '\0';

    while (--len >= 0)
    {
        str[len] = num % 10 + '0';
        num /= 10;
    }

    if (flags->minus)
    {
        if (num < 0)
            write(1, "-", 1);

        write(1, str, ft_strlen(str));
        while (--(flags->width) > ft_strlen(str))
            write(1, " ", 1);
    }
    else
    {
        if (flags->zero && num < 0)
            write(1, "-", 1);

        while (--(flags->width) > ft_strlen(str))
            write(1, flags->zero ? "0" : " ", 1);

        if (!flags->zero && num < 0)
            write(1, "-", 1);

        write(1, str, ft_strlen(str));
    }

    free(str);
}
