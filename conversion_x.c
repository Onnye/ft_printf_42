#include "ft_printf.h"

void    conversion_x(va_list args, t_flags *flags, int uppercase)
{
    unsigned int num = va_arg(args, unsigned int);

    char *hex = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

    int len = 0;
    unsigned int temp = num;

    while (temp > 0)
    {
        temp /= 16;
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
        str[len] = hex[num % 16];
        num /= 16;
    }

    if (flags->minus)
    {
        write(1, str, ft_strlen(str));
        while (--(flags->width) > ft_strlen(str))
            write(1, " ", 1);
    }
    else
    {
        while (--(flags->width) > ft_strlen(str))
            write(1, flags->zero ? "0" : " ", 1);

        write(1, str, ft_strlen(str));
    }

    free(str);
}
