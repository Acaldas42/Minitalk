/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaldas <acaldas@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 01:14:16 by acaldas           #+#    #+#             */
/*   Updated: 2023/01/03 02:18:12 by acaldas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/ft_printf.h"
#define BASE "0123456789abcdef"

int	ft_printhex(unsigned long nbr, int flag)
{
	int	count;

	count = 0;
	if (nbr >= 16)
	{
		count += ft_printhex((nbr / 16), flag);
		count += ft_printhex((nbr % 16), flag);
	}
	else
	{
		if (nbr < 10)
			return (ft_putchar(BASE[nbr]));
		else
			return (ft_putchar(BASE[nbr] - ('x' - flag)));
	}
	return (count);
}
