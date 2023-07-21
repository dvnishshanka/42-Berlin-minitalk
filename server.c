/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:56:07 by dnishsha          #+#    #+#             */
/*   Updated: 2023/07/19 14:56:09 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Global struct to hold bit and current_byte values
t_signal	g_signal;

// Convert bytes to char
static void	btoc(int sig, siginfo_t *info, void *other)
{
	pid_t		client_pid;

	(void) other;
	client_pid = info->si_pid;
	if (sig == SIGUSR1)
		g_signal.current_byte = g_signal.current_byte | (1 << g_signal.bit);
	g_signal.bit --;
	if (g_signal.bit == -1)
	{
		if (g_signal.current_byte == '\0')
			ft_printf("\n");
		else
			write(1, &(g_signal.current_byte), 1);
		g_signal.current_byte = 0;
		g_signal.bit = 7;
	}
	if (kill (client_pid, SIGUSR1) == -1)
		print_error("ERROR IN SENDING SIGNAL");
}

/*
Alternative Approach
	signal(SIGUSR1, btoc);
	signal(SIGUSR2, btoc);

sigemptyset() — Initialize a signal mask to exclude all signals
*/
int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	g_signal.current_byte = 0;
	g_signal.bit = 7;
	ft_printf("PID: %d\n", pid);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = btoc;
	if ((sigaction(SIGUSR1, &sa, NULL) == -1)
		|| (sigaction(SIGUSR2, &sa, NULL) == -1))
		print_error("ERROR IN SETTING UP SIGNAL HANDLER");
	while (1)
		pause();
	return (0);
}
