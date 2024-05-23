/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:31:32 by rel-mora          #+#    #+#             */
/*   Updated: 2024/05/23 16:11:23 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <signal.h>
# include <stdlib.h>
// void	ft_init(void)
// {
// 	g_info.c = 0;
// 	g_info.count = 7;
// 	g_info.i = 0;
// 	g_info.len_bits = 31;
// 	g_info.check_alloc = -1;
// 	g_info.len = 0;
// 	g_info.client_pid = 0;
// }
typedef struct s_server
{
	int len;
	int pid_of_client;
	int new_pid_of_client;
	int len_bit;
	int len_char;
}	t_server;

#endif