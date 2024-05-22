/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:14:56 by rel-mora          #+#    #+#             */
/*   Updated: 2024/01/19 22:20:15 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_str(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		count += ft_put_str("(null)");
		return (count);
	}
	while (*str)
	{
		count += ft_put_char(*str);
		str++;
	}
	return (count);
}
