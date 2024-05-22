/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:07:30 by rel-mora          #+#    #+#             */
/*   Updated: 2024/01/19 22:09:18 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);

int	ft_put_char(int c);
int	ft_put_str(char *str);
int	ft_put_adr(void *adr);
int	ft_put_hexa(unsigned long hexa, int is_upp);
int	ft_put_nbr(int nbr);
int	ft_put_unbr(unsigned int nbr);

#endif
