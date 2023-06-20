/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaldas <acaldas@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 01:14:16 by acaldas           #+#    #+#             */
/*   Updated: 2023/01/03 02:17:30 by acaldas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/ft_printf.h"

int	ft_pflag(unsigned long nbr)
{
	int	count;

	if (nbr == 0)
		count = ft_putstr(NULLTEXT);
	else
	{
		count = ft_putstr("0x");
		count += ft_printhex(nbr, 'x');
	}
	return (count);
}
