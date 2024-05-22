/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:13:37 by rel-mora          #+#    #+#             */
/*   Updated: 2024/01/19 22:14:40 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_nbr(int nbr)
{
	int			count;
	long long	long_nbr;

	count = 0;
	long_nbr = nbr;
	if (long_nbr < 0)
	{
		count += ft_put_char('-');
		long_nbr = -long_nbr;
	}
	if (long_nbr >= 10)
	{
		count += ft_put_nbr(long_nbr / 10);
		count += ft_put_nbr(long_nbr % 10);
	}
	if (long_nbr < 10)
		count += ft_put_char(long_nbr + '0');
	return (count);
}
