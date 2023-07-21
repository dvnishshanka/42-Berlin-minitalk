/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:25:40 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/17 13:42:03 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_nbr(long int n)
{
	size_t	output;

	output = 0;
	if (n < 0)
	{
		output += print_char('-');
		output += print_nbr(-n);
	}
	else if (n > 9)
	{
		output += print_nbr(n / 10);
		output += print_char((n % 10) + '0');
	}
	else if (n < 10)
		output += print_char(n + '0');
	return (output);
}
