/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:40:23 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/17 14:35:25 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

static size_t	print_p(unsigned long int num)
{
	size_t	output;

	output = 0;
	if (num == 0)
		return (print_str("(nil)"));
	else
	{
		output += print_str("0x");
		output += print_nbr_hex(num, "0123456789abcdef", 16);
	}
	return (output);
}

static size_t	convert(va_list args, int c)
{
	size_t	output;

	output = 0;
	if (c == 'c')
		output += print_char((char)(va_arg(args, int)));
	else if (c == 's')
		output += print_str(va_arg(args, char *));
	else if (c == 'p')
		output += print_p((unsigned long int)va_arg(args, void *));
	else if (c == 'd' )
		output += print_nbr(va_arg(args, int));
	else if (c == 'i')
		output += print_nbr(va_arg(args, int));
	else if (c == 'u')
		output += print_nbr(va_arg(args, unsigned int));
	else if (c == 'x')
		output += print_nbr_hex(va_arg(args, unsigned int),
				"0123456789abcdef", 16);
	else if (c == 'X')
		output += print_nbr_hex(va_arg(args, unsigned int),
				"0123456789ABCDEF", 16);
	else if (c == '%')
		output += print_char(c);
	return (output);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	size_t	output;

	i = 0;
	output = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			output += convert(args, str[i]);
		}
		else
			output += print_char(str[i]);
		i++;
	}
	va_end(args);
	return (output);
}
