/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaldas <acaldas@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 01:14:16 by acaldas           #+#    #+#             */
/*   Updated: 2023/01/03 02:17:36 by acaldas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/ft_printf.h"

static void	fill_tab(char *tab, int nb, int size)
{
	int	sign;

	sign = 1;
	tab[size--] = '\0';
	if (nb == (1 << 31))
	{
		tab[size--] = 8 + '0';
		nb = (nb / 10);
	}
	if (nb < 0)
	{
		sign = -1;
		nb *= sign;
	}
	while (size > 0)
	{
		tab[size--] = (nb % 10) + '0';
		nb /= 10;
	}
	if (sign < 0)
		tab[0] = '-';
	else
		tab[0] = (nb % 10) + '0';
}

static size_t	get_size(int nb)
{
	size_t	count;

	count = 1;
	if (nb == (1 << 31))
	{
		nb = (nb + 1) * -1;
		count++;
	}
	if (nb < 0)
	{
		nb *= -1;
		count++;
	}
	while (nb > 9)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

int	ft_itoa(int nbr)
{
	char	*str;
	size_t	size;

	size = get_size(nbr);
	str = (char *) ft_calloc(size + 1, sizeof(char));
	fill_tab(str, nbr, size);
	ft_putstr(str);
	free(str);
	return (size);
}
