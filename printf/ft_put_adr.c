/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_adr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:09:52 by rel-mora          #+#    #+#             */
/*   Updated: 2024/01/21 13:44:52 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_adr(void *adr)
{
	int	count;

	count = 0;
	if (adr == NULL)
		return (count += ft_put_str("0x0"));
	count += ft_put_str("0x");
	count += ft_put_hexa((unsigned long)adr, 0);
	return (count);
}
