/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:55:38 by dnishsha          #+#    #+#             */
/*   Updated: 2023/07/19 14:55:40 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_response;

void	feedback_handler(int sig)
{
	if (sig == SIGUSR1)
		g_response = 1;
}

void	wait_for_feedback(void)
{
	if (g_response == 0)
		pause();
	g_response = 0;
}

// Convert char to bit
// Instead of wait_for_feedback(), can use usleep() as well to delay
void	ctob(int server_pid, char c)
{
	int					bit;
	struct sigaction	sa;

	bit = 7;
	g_response = 0;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = feedback_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		print_error("ERROR IN SETTING UP SIGNAL HANDLER");
	while (bit >= 0)
	{
		if ((c & (0x1 << bit)) && (kill (server_pid, SIGUSR1) == -1))
			print_error("ERROR IN SENDING SIGNAL");
		if (!(c & (0x1 << bit)) && (kill (server_pid, SIGUSR2) == -1))
			print_error("ERROR IN SENDING SIGNAL");
		wait_for_feedback();
		bit --;
	}
}

int	main(int argc, char **argv)
{
	int					server_pid;
	char				*msg;

	msg = NULL;
	if (argc != 3 || (!(*argv[2])))
		print_error("ERROR IN INPUTS");
	else
	{
		server_pid = ft_atoi(argv[1]);
		if (server_pid <= 0)
			print_error("ERROR IN INPUTS");
		msg = argv[2];
	}
	while (*msg)
	{
		ctob(server_pid, *msg);
		msg ++;
	}
	ctob(server_pid, *msg);
	return (0);
}
