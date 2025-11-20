/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:15:16 by nmontard          #+#    #+#             */
/*   Updated: 2025/11/20 16:57:01 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_put_hex_nbr.h"
#include "ft_put_memory.h"
#include "ft_putchar.h"
#include "ft_putnbr.h"
#include "ft_putstr.h"
#include "ft_putunbr.h"
#include <stdarg.h>

int	print_param_type(char c, va_list va_ptr)
{
	// verifier pour long ou unsigned int
	if (c == 'c')
		ft_putchar((char)va_arg(va_ptr, int));
	else if (c == 's')
		ft_putstr(va_arg(va_ptr, char *));
	else if (c == 'p')
		ft_put_memory(va_arg(va_ptr, void *));
	else if (c == 'd')
		ft_putnbr(va_arg(va_ptr, int));
	else if (c == 'i')
		ft_putnbr(va_arg(va_ptr, int));
	else if (c == 'u')
		ft_putunbr(va_arg(va_ptr, unsigned int));
	else if (c == 'x')
		ft_put_hex_nbr(va_arg(va_ptr, long), 1);
	else if (c == 'X')
		ft_put_hex_nbr(va_arg(va_ptr, long), 0);
	else if (c == '%')
		ft_putchar('%');
	else
		return (0);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	va_ptr;
	int		i;

	i = -1;
	if (!str)
		return (-1);
	va_start(va_ptr, str);
	while (str[++i] != '\0')
	{
		if (str[i] == '%')
		{
			if (!print_param_type(str[i + 1], va_ptr))
			{
				ft_putchar(str[i]);
				i++;
				if (str[i] == '\0')
					break ;
			}
			else
				i += 2;
		}
		ft_putchar(str[i]);
	}
	va_end(va_ptr);
	return (1);
}

#include <stdio.h>

int	main(void)
{
	char var = 's';
	char *ptr = &var;
	char *str = "str";
	unsigned int us_int = 4294967295;
	long long_var = 9223372036854775804;
	str = 0;
	ptr = 0;
	printf("printf : dsds   %p %i %s %d %u %x %X %%\n", ptr, 4, str, 2147483647,
		us_int, long_var, long_var);
	ft_printf("ft_printf : dsds   %p %i %s %d %u %x %X %%\n", ptr, 4, str,
		2147483647, us_int, long_var, long_var);
	// printf("%d\n", printf(str, ptr, 4, str, 2147483647, us_int, long_var,
	// 		long_var));
	// printf("%d\n", ft_printf(str, ptr, 4, str, 2147483647, us_int, long_var,
	// 	long_var));
}