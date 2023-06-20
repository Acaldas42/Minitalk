/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaldas <acaldas@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 01:14:16 by acaldas           #+#    #+#             */
/*   Updated: 2023/01/03 02:17:55 by acaldas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	if (!str)
		return (-1);
	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += check_flag(*str, args);
		}
		else
		{
			count++;
			ft_putchar(*str);
		}
		str++;
	}
	va_end(args);
	return (count);
}

int	check_flag(char flag, va_list arg)
{
	if (flag == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (flag == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (flag == 'd' || flag == 'i')
		return (ft_itoa(va_arg(arg, int)));
	if (flag == 'u')
		return (ft_utoa(va_arg(arg, unsigned int)));
	if (flag == 'x' || flag == 'X')
		return (ft_printhex(va_arg(arg, unsigned int), flag));
	if (flag == 'p')
		return (ft_pflag(va_arg(arg, unsigned long int)));
	else
		return (ft_putchar(flag));
}
