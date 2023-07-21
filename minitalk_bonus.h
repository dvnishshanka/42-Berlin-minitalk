/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:28:30 by dnishsha          #+#    #+#             */
/*   Updated: 2023/07/21 12:28:39 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

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
