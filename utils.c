/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:56:41 by dnishsha          #+#    #+#             */
/*   Updated: 2023/07/19 14:56:43 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;

	sign = 1;
	num = 0;
	if (!*str)
		print_error("ERROR IN INPUTS");
	if (*str && *str == '-' && (*(str + 1) <= '9' && *(str + 1) >= '0'))
	{
		sign = -1;
		str ++;
	}
	while (*str)
	{
		if (*str > '9' || *str < '0')
			print_error("ERROR IN INPUTS");
		num *= 10;
		num += *str - '0';
		str ++;
	}
	return (num * (sign));
}
