/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:04:57 by rel-mora          #+#    #+#             */
/*   Updated: 2024/05/19 20:28:26 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void 	ft_handle_enter(int ac, char **av)
{
	int	pid;
    // int return_kill;

	if (ac != 3)
	{
		ft_printf("the number of the argument to entered is not allowed  :(\n");
		exit(1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_printf("The Number To Enter is Negative Or 0 :(\n");
		exit(1);
	}
    // return_kill = kill(pid, SIGUSR1);
	// if (return_kill == -1)
	// {
	// 	ft_printf("Invalide PID\n");
	// 	exit(1);
	// }
	// return (pid);
}
void ft_send_len(char *av)
{
	int len;
	int count_len;
	int i;
	int tmp;

	i = 0;
	len = ft_strlen(av);
	tmp = 0;
	count_len = 0;
	while(i <= 32)
	{
		// ft_printf("%d", tmp);
		tmp = len << i & 1;
		i++;
	}

}

void ft_send_char(char *av, int pid)
{
	int i = 128;
	int j = 0;
	while(av[j])
	{
		while(i > 0)
		{
			if (av[j]>= i)
				kill(pid, SIGUSR1);
			else
			{
				kill(pid, SIGUSR2);
				av[j] -= i;
			}
			i /= 2;
		}
		j++;
	}

}
void ft_send(char *av, int pid)
{
	int len;

	len = ft_strlen(av);

	ft_send_char(av, pid);
	// ft_send_len(av);
	// while()
}
int	main(int ac, char **av)
{
	int pid;

    ft_handle_enter(ac, av);
	pid = ft_atoi(av[1]);
	ft_send(av[2], pid);
	return (0);
}
