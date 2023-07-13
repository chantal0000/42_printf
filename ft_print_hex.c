/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:38:50 by chbuerge          #+#    #+#             */
/*   Updated: 2023/07/13 13:39:04 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* hexadecimal %x
255 = ff or FF
f = 15 -> (15 * 16(base of hex)^1(the leftmost position))
(15 * 16^1) + (15 * 16^0) = (15 * 16) + (15 * 1) = 240 + 15 = 255

10 - 15 -> ABCDEF
calculates ASCII value of the character to be printed on the numeric value of
hex digit (nb)
nb -> numeric value of the dex digit
nb - 10 -> offset of A from 0
ft_putchar_fd((nb - 10 + 'A'), 1);
*/

int	ft_print_hex(unsigned long int nb, char specifier)
{
	char	*str;
	int		length;

	length = 0;
	if (nb == '0')
		write(1, "0", 1);
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
				ft_putchar_fd((nb - 10 + 'a'), 1);
		}
	}
	str = ft_itoa(nb);
	length = ft_strlen(str);
	return (length);
}
