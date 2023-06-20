/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaldas <acaldas@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 01:14:16 by acaldas           #+#    #+#             */
/*   Updated: 2023/01/03 02:13:56 by acaldas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# ifdef __APPLE__
#  define NULLTEXT "0x0"
# else
#  define NULLTEXT "(nil)"
# endif

int		check_flag(char flag, va_list arg);
int		ft_itoa(int nbr);
int		ft_nsize(unsigned int n);
int		ft_pflag(unsigned long nbr);
int		ft_printf(const char *str, ...);
int		ft_printhex(unsigned long nbr, int flag);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_utoa(unsigned int nbr);
void	*ft_calloc(size_t count, size_t size);

#endif
