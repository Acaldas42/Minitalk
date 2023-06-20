/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaldas <acaldas@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 01:14:16 by acaldas           #+#    #+#             */
/*   Updated: 2023/01/03 02:19:49 by acaldas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/ft_printf.h"

int	ft_utoa(unsigned int nbr)
{
	int		size;
	char	*str;

	size = ft_nsize(nbr);
	str = (char *) malloc (size + 1);
	if (!str)
		return (0);
	str[size] = 0;
	while (size > 0)
	{
		str[size - 1] = (nbr % 10) + '0';
		nbr /= 10;
		size--;
	}
	size = ft_putstr(str);
	free(str);
	return (size);
}

int	ft_nsize(unsigned int n)
{
	int	count;

	count = 1;
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	i;

	if (size > (~(1 << 31) / count))
		return (NULL);
	mem = malloc (size * count);
	if (!mem)
		return (NULL);
	i = 0;
	while (i < (count * size))
	{
		((char *) mem)[i] = 0;
		i++;
	}
	return (mem);
}
