#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct      s_flags
{
    int             minus;
    int             zero;
    int             dot;
    int             width;
    int             sharp;
    int             space;
    int             plus;
}                   t_flags;

int     ft_printf(const char *format, ...);
void    parse_flags(const char **format, t_flags *flags, va_list args);
void    conversion_c(va_list args, t_flags *flags);
void    conversion_s(va_list args, t_flags *flags);
void    conversion_p(va_list args, t_flags *flags);
void    conversion_di(va_list args, t_flags *flags);
void    conversion_u(va_list args, t_flags *flags);
void    conversion_x(va_list args, t_flags *flags, int uppercase);
void    conversion_percent(t_flags *flags);

#endif
