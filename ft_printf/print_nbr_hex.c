/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:13:59 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/17 13:54:57 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_nbr_hex(unsigned long int n, char *symbols,
	unsigned long int base)
{
	size_t			output;

	output = 0;
	if (n >= base)
	{
		output += print_nbr_hex((n / base), symbols, base);
		output += print_char(symbols[(n % base)]);
	}
	else if (n < base)
		output += print_char(symbols[n]);
	return (output);
}
