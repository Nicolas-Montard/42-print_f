/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:55:39 by nmontard          #+#    #+#             */
/*   Updated: 2025/11/21 14:42:11 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_putstr(char *str, int *char_print)
{
	int	i;

	if (!str)
	{
		write(1, "(null)", 6);
		*char_print += 6;
		return ;
	}
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i], char_print);
		i++;
	}
}
