/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:57:09 by dnishsha          #+#    #+#             */
/*   Updated: 2023/07/19 14:57:11 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <signal.h>

typedef struct Signal {
	int	bit;
	int	current_byte;
}	t_signal;

// Util Functions
void	print_error(char *msg);
int		ft_atoi(const char *str);

#endif
