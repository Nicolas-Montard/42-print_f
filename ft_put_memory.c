/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:35:56 by nmontard          #+#    #+#             */
/*   Updated: 2025/11/20 15:51:13 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putchar.h"
#include "ft_putstr.h"

static void	ft_setbase(char base[])
{
	int		i;
	char	letter;

	letter = 'a';
	i = 0;
	while (i < 10)
	{
		base[i] = i + '0';
		i++;
	}
	while (i < 16)
	{
		base[i] = letter;
		letter++;
		i++;
	}
}

static void	ft_put_longtohex_nbr(unsigned long nb, char base[])
{
	if (nb > 16)
	{
		ft_put_longtohex_nbr(nb / 16, base);
		ft_put_longtohex_nbr(nb % 16, base);
	}
	else
		ft_putchar(base[nb]);
}

void	ft_put_memory(const void *addr)
{
	char base[16];
	unsigned long nb;

	if (!addr)
	{
		ft_putstr("(nil)");
		return ;
	}
	ft_putstr("0x");
	ft_setbase(base);
	nb = (unsigned long)addr;
	ft_put_longtohex_nbr(nb, base);
}