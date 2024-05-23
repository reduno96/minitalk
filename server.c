/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:31:48 by rel-mora          #+#    #+#             */
/*   Updated: 2024/05/23 16:58:37 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_server	server;

void	ft_reset_server(void)
{
	server.len = 0;
	server.pid_of_client = 0;
	server.new_pid_of_client = 0;
	server.len_bit = 0;
	server.len_char = 0;
}

void	to_handler_receive(int sig_num, siginfo_t *info, void *arg)
{
	static int	i = 31;

	server.pid_of_client = info->si_pid;
	if (server.pid_of_client != info->si_pid)
		ft_reset_server();

}

int	main(void)
{
	struct sigaction	act;

	ft_printf("PID Of The server: %d", getpid());
	act.sa_sigaction = to_handler_receive;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause ;
	return (0);
}
