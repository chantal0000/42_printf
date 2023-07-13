/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:40:37 by chbuerge          #+#    #+#             */
/*   Updated: 2023/07/13 13:40:41 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* %u */
void	ft_putnbr_u(int n)
{
	long int	nb;

	nb = n;
	if (nb > 9)
	{
		ft_putnbr_u(nb / 10);
		ft_putchar_fd((nb % 10 + 48), 1);
	}
	else
		ft_putchar_fd((nb + 48), 1);
}

int	ft_print_u_nbr(unsigned int nb)
{
	int		length;
	char	*s;

	length = 0;
	s = ft_itoa(nb);
	length = ft_strlen(s);
	ft_putnbr_u(nb);
	return (length);
}
