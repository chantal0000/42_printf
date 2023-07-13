/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:39:27 by chbuerge          #+#    #+#             */
/*   Updated: 2023/07/13 18:18:12 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//#include <stdio.h>
/*
cases to handle:
done:
1. %c Prints a single character.
2. %s Prints a string (as defined by the common C convention).

to do:
3. %p The void * pointer argument has to be printed in hexadecimal format.
4. %d Prints a decimal (base 10) number.
	- prints but does not count
5. %i Prints an integer in base 10.
6. %u Prints an unsigned decimal (base 10) number.
7. %x Prints a number in hexadecimal (base 16) lowercase format.
8. %X Prints a number in hexadecimal (base 16) uppercase format.
9. %% Prints a percent sign.

RETURN NULL EVERYWHERE?
*/
int	ft_eval_specifier(va_list args, const char specifier)
{
	int	length;

	length = 0;
	if (specifier == 'c')
		length = length + ft_print_char(va_arg(args, int));
	else if (specifier == 's')
		length = length + ft_print_str(va_arg(args, char *));
	else if (specifier == 'p')
		length = length + ft_print_p(va_arg(args, unsigned long int));
	else if (specifier == 'd' || specifier == 'i')
		length = length + ft_print_nbr(va_arg(args, int));
	else if (specifier == 'u')
		length = length + ft_print_u_nbr(va_arg(args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		length = length + ft_print_hex
			((unsigned int)va_arg(args, unsigned long int), specifier);
	else if (specifier == '%')
		length = length + ft_print_char('%');
	return (length);
}

int	ft_printf(const char *format, ...)
{
	int		length;
	int		i;
	va_list	args;

	length = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			length = length + ft_eval_specifier(args, format[i + 1]);
			i++;
		}
		else
			length = length + ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (length);
}
/*
#include <limits.h>
#include <stdio.h>

int main()
{

	ft_printf("m: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%
	%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n",
	'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0",
	 0, 0 ,0 ,0, 42, 0);
	printf("o: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%
	%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B',
	"-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);

	//ft_printf("%u\n", -4);
	//printf("%u\n", -4);

ft_printf("m: %p \n", -1);
ft_printf("m: %p \n", 15);
ft_printf("m: %p \n", 16);
ft_printf("m: %p \n", 17);
ft_printf("m: %p %p \n", LONG_MIN, LONG_MAX);
ft_printf("m: %p %p \n", INT_MIN, INT_MAX);
ft_printf("m: %p %p \n", ULONG_MAX, -ULONG_MAX);
ft_printf("m: %p %p \n", 0,0);

printf(" %p \n", -1);
printf(" %p \n", 15);
printf(" %p \n", 16);
printf(" %p \n", 17);
printf(" %p %p \n", LONG_MIN, LONG_MAX);
printf(" %p %p \n", INT_MIN, INT_MAX);
printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
printf(" %p %p \n", 0,0);


return (0);
}*/
