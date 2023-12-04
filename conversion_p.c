#include "ft_printf.h"

void    conversion_p(va_list args, t_flags *flags)
{
    long long ptr = (long long)va_arg(args, void*);

    char *hex = "0123456789abcdef";
    char *str = NULL;

    if (ptr == 0 && flags->dot == 0)
        str = "";
    else
    {
        int len = 0;
        long long temp = ptr;
        while (temp > 0)
        {
            temp /= 16;
            len++;
        }

        if (ptr == 0)
            len = 1;

        if (flags->dot > len)
            len = flags->dot;

        str = (char *)malloc(len + 1);
        str[len] = '\0';

        while (--len >= 0)
        {
            str[len] = hex[ptr % 16];
            ptr /= 16;
        }
    }

    if (flags->minus)
    {
        write(1, "0x", 2);
        write(1, str, ft_strlen(str));
        while (--(flags->width) > ft_strlen(str) + 2)
            write(1, " ", 1);
    }
    else
    {
        while (--(flags->width) > ft_strlen(str) + 2)
            write(1, " ", 1);
        write(1, "0x", 2);
        write(1, str, ft_strlen(str));
    }

    free(str);
}
