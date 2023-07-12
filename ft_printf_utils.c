/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:25:41 by chbuerge          #+#    #+#             */
/*   Updated: 2023/07/12 18:07:31 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
/*
cases to handle:
1. %c Prints a single character.
2. %s Prints a string (as defined by the common C convention).
3. %p The void * pointer argument has to be printed in hexadecimal format.
4. %d Prints a decimal (base 10) number.
5. %i Prints an integer in base 10.
6. %u Prints an unsigned decimal (base 10) number.
7. %x Prints a number in hexadecimal (base 16) lowercase format.
8. %X Prints a number in hexadecimal (base 16) uppercase format.
9. %% Prints a percent sign.
*/
/* %c */
int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

/* %s */
int	ft_print_str(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		ft_print_char(s[i]);
		i++;
	}
	return(i);
}



/* %i and %d */
int	ft_print_nbr(int nb)
{
	int		length;
	char	*s;

	length = 0;
	s = ft_itoa(nb);
	length = ft_strlen(s);
	ft_putnbr_fd(nb, 1);

	return (length);
}

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

/* hexadecimal %x
255 = ff or FF
f = 15 -> (15 * 16(base of hex)^1(the leftmost position))
(15 * 16^1) + (15 * 16^0) = (15 * 16) + (15 * 1) = 240 + 15 = 255*/

int	ft_print_hex(unsigned int nb, char specifier)
{
	char *str;
/*
	if (specifier == 'x')
		str = "123456789abcdef";
	else
		str = "123456789ABCDEF";
*/
	if (nb == '0')
	{
		write(1, "0", 1);
	}
	else if (nb > 15)
	{
		ft_print_hex(nb / 16, specifier);
		ft_print_hex(nb % 16, specifier);
	}
	else
	{
			if (nb <= 9)
					ft_putchar_fd((nb + 48), 1);
			else
				{
					if (specifier == 'X')
						ft_putchar_fd((nb - 10 + 'A'), 1);
					else if (specifier == 'x')
						ft_putchar_fd((nb - 10 + 'a'),1);
				}
	}
	return (0);
}
