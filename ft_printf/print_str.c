/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:23:12 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/17 09:40:53 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(const char *s)
{
	size_t	i;
	size_t	output;

	i = 0;
	output = 0;
	if (!s)
	{
		return (print_str("(null)"));
	}
	while (s[i])
	{
		output += print_char(s[i]);
		i++;
	}
	return (output);
}
