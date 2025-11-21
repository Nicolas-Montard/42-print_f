/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:59:08 by nmontard          #+#    #+#             */
/*   Updated: 2025/11/21 16:21:26 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *char_print)
{
	unsigned int	nb;

	if (n < 0)
	{
		nb = n * -1;
		ft_putchar('-', char_print);
	}
	else
		nb = n;
	if (nb > 9)
	{
		ft_putnbr(nb / 10, char_print);
		ft_putnbr(nb % 10, char_print);
	}
	else
		ft_putchar(nb + 48, char_print);
}
