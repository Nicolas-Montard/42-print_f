/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:15:31 by nmontard          #+#    #+#             */
/*   Updated: 2025/11/21 13:47:42 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr(unsigned int nb, int *char_print)
{
	if (nb > 9)
	{
		ft_putunbr(nb / 10, char_print);
		ft_putunbr(nb % 10, char_print);
	}
	else
		ft_putchar(nb + 48, char_print);
}