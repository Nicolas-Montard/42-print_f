/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:24:58 by nmontard          #+#    #+#             */
/*   Updated: 2025/11/20 16:58:56 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putchar.h"

void static	ft_setbase(char base[], int is_lc)
{
	int		i;
	char	letter;

	if (is_lc)
		letter = 'a';
	else
		letter = 'A';
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

void	ft_put_hex_nbr(unsigned int n, int is_lc)
{
	char			base[16];
	unsigned int	nb;

	ft_setbase(base, is_lc);
	if (n < 0)
	{
		nb = n * -1;
		ft_putchar('-');
	}
	else
		nb = n;
	if (nb > 16)
	{
		ft_put_hex_nbr(nb / 16, is_lc);
		ft_put_hex_nbr(nb % 16, is_lc);
	}
	else
		ft_putchar(base[nb]);
}
