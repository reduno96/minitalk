/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:12:29 by rel-mora          #+#    #+#             */
/*   Updated: 2024/01/23 11:09:57 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hexa(unsigned long hexa, int is_upper)
{
	int	count;

	count = 0;
	if (hexa >= 16)
	{
		count += ft_put_hexa(hexa / 16, is_upper);
		count += ft_put_hexa(hexa % 16, is_upper);
	}
	else if (hexa < 10)
		count += ft_put_char(hexa + '0');
	else
	{
		if (is_upper)
			count += ft_put_char(hexa - 10 + 'A');
		else
			count += ft_put_char(hexa - 10 + 'a');
	}
	return (count);
}
