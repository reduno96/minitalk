/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:15:22 by rel-mora          #+#    #+#             */
/*   Updated: 2024/01/19 22:19:09 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unbr(unsigned int nbr)
{
	unsigned int	long_nbr;
	int				count;

	count = 0;
	long_nbr = nbr;
	if (long_nbr >= 10)
	{
		count += ft_put_unbr(long_nbr / 10);
		count += ft_put_unbr(long_nbr % 10);
	}
	if (long_nbr < 10)
		count += ft_put_char(long_nbr + '0');
	return (count);
}
