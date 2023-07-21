/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:55:52 by dnishsha          #+#    #+#             */
/*   Updated: 2023/07/21 14:25:06 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	g_response;

void	feedback_handler(int sig)
{
	if (sig == SIGUSR1)
		g_response = 1;
}

void	wait_for_feedback(int is_end, int bit)
{
	if (g_response == 0)
		pause();
	if (is_end && (bit == 0))
		ft_printf("Received\n");
	g_response = 0;
}

// Convert char to bit
void	ctob(int server_pid, char c, int is_end)
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
		wait_for_feedback(is_end, bit);
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
		ctob(server_pid, *msg, 0);
		msg ++;
	}
	ctob(server_pid, *msg, 1);
	return (0);
}
