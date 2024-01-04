/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltufo <ltufo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:06:48 by ltufo             #+#    #+#             */
/*   Updated: 2023/12/19 13:04:16 by ltufo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int ft_putchar(char c);
int ft_putstr(char *str);
int ft_putnbr(int n);
int ft_putunbr(unsigned int n);
void ft_itoa_base(unsigned long long num, char *base, char *buffer, int *index);
int ft_putnbrbase(unsigned long long n, char *base);
int ft_putptr(void *ptr);
int ft_printf(const char *format, ...);

#endif