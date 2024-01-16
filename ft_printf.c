/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltufo <ltufo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:02:46 by ltufo             #+#    #+#             */
/*   Updated: 2023/12/19 12:53:37 by ltufo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c')
                count += ft_putchar(va_arg(args, int));
            else if (*format == 's')
                count += ft_putstr(va_arg(args, char *));
            else if (*format == 'd' || *format == 'i')
                count += ft_putnbr(va_arg(args, int));
            else if (*format == 'p')
                count += ft_putptr(va_arg(args, void *));
            else if (*format == 'u')
                count += ft_putunbr(va_arg(args, unsigned int));
            else if (*format == 'x')
                count += ft_putnbrbase(va_arg(args, unsigned int), "0123456789abcdef");
            else if (*format == 'X')
                count += ft_putnbrbase(va_arg(args, unsigned int), "0123456789ABCDEF");
            else if (*format == '%')
                count += ft_putchar('%');

            // Move to the next format specifier
            format++;
        }
        else
        {
            count += ft_putchar(*format);
            format++;
        }
    }

    va_end(args);
    return count;
}

/*
int main()
{
    // Test avec différents types d'arguments

    int integer = 42;
    unsigned int unsignedInteger = 12345;
    char character = 'A';
    char *string = "Hello, World!";
    void *pointer = NULL;

    // Test de ft_printf avec différentes catégories d'arguments
    ft_printf("Integer: %d\n", integer);
    ft_printf("Unsigned Integer: %u\n", unsignedInteger);
    ft_printf("Character: %c\n", character);
    ft_printf("String: %s\n", string);
    ft_printf("Pointer: %p\n", pointer);

    // Test du cas particulier ft_printf(0)
    int result = ft_printf("Testing ft_printf(0): %d\n", 0);
    
    if (result == -1) {
        // Handle potential error from ft_printf
        ft_printf("Error in ft_printf.\n");
    }

    return 0;
}
*/