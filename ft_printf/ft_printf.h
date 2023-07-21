/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:40:27 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/17 13:54:47 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);

// Support functions
int		print_char(int c);
int		print_str(const char *s);
size_t	print_nbr(long int n);
size_t	print_nbr_hex(unsigned long int n, char *symbols,
			unsigned long int base);
#endif
