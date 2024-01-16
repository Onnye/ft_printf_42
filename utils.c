/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltufo <ltufo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:40:53 by ltufo             #+#    #+#             */
/*   Updated: 2023/12/19 12:53:15 by ltufo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}

int ft_putstr(char *str)
{
    if (str == NULL)
        return write(1, "(null)", 6);

    int len = 0;
    while (str[len])
    {
        write(1, &str[len], 1);
        len++;
    }
    return len;
}

int ft_putunbr(unsigned int n)
{
    int count = 0;
    if (n >= 10)
        count += ft_putunbr(n / 10);
    count += ft_putchar(n % 10 + '0');
    return count;
}

int ft_putnbr(int n)
{
    int count = 0;
    if (n < 0)
    {
        count += ft_putchar('-');
        count += ft_putunbr((unsigned int)(~n + 1));  // Use ~ and + 1 to invert bits
        return count;
    }
    return ft_putunbr((unsigned int)n);
}

void ft_itoa_base(unsigned long long num, char *base, char *buffer, int *index)
{
    size_t base_len = 0;
    while (base[base_len])
        base_len++;

    if (num >= base_len)
        ft_itoa_base(num / base_len, base, buffer, index);

    buffer[(*index)++] = base[num % base_len];
}

int ft_putnbrbase(unsigned long long n, char *base)
{
    char buffer[20]; // Assuming a reasonable buffer size
    int index = 0;

    ft_itoa_base(n, base, buffer, &index);
    buffer[index] = '\0';

    return ft_putstr(buffer);
}

int ft_putptr(void *ptr)
{
    char hex_base[] = "0123456789abcdef";
    
    // Determine the size of the pointer on the platform
    size_t pointer_size = sizeof(void *);

    // Allocate memory for the buffer dynamically
    char *hex_buffer = (char *)malloc(pointer_size * 2 + 3); // +2 for "0x", +1 for null terminator

    if (hex_buffer == NULL) {
        // Handle memory allocation failure
        return -1;
    }

    int index = 0;
    hex_buffer[index++] = '0';
    hex_buffer[index++] = 'x';

    ft_itoa_base((unsigned long long)ptr, hex_base, hex_buffer, &index);

    hex_buffer[index] = '\0';

    int count = ft_putstr(hex_buffer);

    // Free the dynamically allocated memory
    free(hex_buffer);

    return count;
}
