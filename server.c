/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:31:48 by rel-mora          #+#    #+#             */
/*   Updated: 2024/05/23 19:55:45 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	to_handler_receive(int sig_num, siginfo_t *info, void *tst)
{
	static unsigned char	character;
	static int				index_bit;
	static pid_t			last_pid = -1;

	(void)tst;
	if (info->si_pid != last_pid)
	{
		last_pid = info->si_pid;
		index_bit = 0;
		character = 0;
	}
	character |= (sig_num == SIGUSR1);
	index_bit++;
	if (index_bit == 8)
	{
		if (character == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", character);
		index_bit = 0;
		character = 0;
	}
	else
		character = character << 1;
}

int	main(void)
{
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	ft_printf("PID Of The server: %d\n", getpid());
	act.sa_sigaction = to_handler_receive;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
	{
	}
	return (0);
}
