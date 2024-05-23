/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:04:57 by rel-mora          #+#    #+#             */
/*   Updated: 2024/05/23 19:55:37 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handle_enter(int ac, char **av)
{
	int	pid;
	int	return_kill;

	if (ac != 3)
	{
		ft_printf("the number of the argument is not allowed\n");
		exit(1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_printf("The Number To Enter is Negative Or 0 :(\n");
		exit(1);
	}
	return_kill = kill(pid, 0);
	if (return_kill == -1)
	{
		ft_printf("Invalide PID\n");
		exit(1);
	}
}

void	ft_send_char(char *av, int pid)
{
	int	i;
	int	j;

	j = 0;
	while (av[j])
	{
		i = 7;
		while (i >= 0)
		{
			if (av[j] >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(200);
			i--;
		}
		j++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	len;

	ft_handle_enter(ac, av);
	len = ft_strlen(av[2]);
	pid = ft_atoi(av[1]);
	ft_send_char(av[2], pid);
	return (0);
}
