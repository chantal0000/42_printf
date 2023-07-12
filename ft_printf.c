/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:39:27 by chbuerge          #+#    #+#             */
/*   Updated: 2023/07/12 18:08:13 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>


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
	//else if (specifier == 'p')
	//...
	else if (specifier == 'd' || specifier == 'i')
		length = length + ft_print_nbr(va_arg(args, int));
	else if (specifier == 'u')
		length = length + ft_print_u_nbr(va_arg(args, unsigned int));
	else if (specifier == 'x')
		length = length + ft_print_hex(va_arg(args, unsigned int), specifier);
	else if (specifier == 'X')
		length = length + ft_print_hex(va_arg(args, unsigned int), specifier);
	else if (specifier == '%')
		length = length + ft_print_char('%');
	return (length);
}

int	ft_printf(const char *format, ...)
{
	int	length;
	int	i;
	va_list	args;


	length = 0;
	i = 0;
	va_start(args, format);
	if (format == NULL)
	return (-1);
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
	/// ALARM DELTE PRINTF
	//printf("length: %d\n", length);
	return (length);
}

/* MAIN FUNCTION */

int main()
{
	//printf("i: %i\n", ft_printf("char c: hello %c\n", 'o'));
/*
	ft_printf("%c\n", '0');
	ft_printf(" %c\n", '0' - 256);
	ft_printf("%c \n", '0' + 256);
	ft_printf(" %c %c %c \n", ' ', ' ', ' ');
	ft_printf(" %c %c %c \n", '1', '2', '3');
	ft_printf(" %c %c %c \n", '2', '1', 0);
	ft_printf(" %c %c %c \n", 0, '1', '2');

	printf("o:%c\n", '0');
	printf("o: %c\n", '0' - 256);
	printf("o:%c \n", '0' + 256);
	printf("o: %c %c %c \n", ' ', ' ', ' ');
	printf("o: %c %c %c \n", '1', '2', '3');
	printf("o: %c %c %c \n", '2', '1', 0);
	printf("o: %c %c %c \n", 0, '1', '2');

	ft_printf("%s\n", "hi");
	ft_printf(" %s\n", "");
	ft_printf("%s \n", "");
	ft_printf(" %s \n", "");
	ft_printf(" %s \n", "-");
	ft_printf(" %s %s \n", "", "-");
	ft_printf(" %s %s \n", " - ", "");
	ft_printf(" %s %s %s %s %s \n", " - ", "", "4", "", "2 ");
	ft_printf(" NULL %s NULL \n", NULL);

	printf("o:%s\n", "");
	printf("o: %s\n", "");
	printf("o:%s \n", "");
	printf("o: %s \n", "");
	printf("o: %s \n", "-");
	printf("o: %s %s \n", "", "-");
	printf("o: %s %s \n", " - ", "");
	printf("o: %s %s %s %s %s \n", " - ", "", "4", "", "2 ");
	printf("o: NULL %s NULL \n", NULL);

	ft_printf("int i 421: %i\n", 421);
	ft_printf("int d -42: %d\n", -42);
	ft_printf("percent: %%\n");
	ft_printf("int u -420: %u\n", -420);
	ft_printf("int u 20: %u\n", 20);

	printf("i: %i\n", printf("u: %u\n", -420));
	printf("u: %u\n", 20);*/
	int decimalNumber = 22113;

	ft_printf("Decimal: %d\n", decimalNumber);
	//ft_printf("x: %x\n", 255);
	ft_printf("X: %X\n", decimalNumber);
	ft_printf("x: %x\n", decimalNumber);
//	ft_printf("X: %X\n", 0);

	printf("Decimal: %x\n", decimalNumber);
//	printf("x: %x\n", 255);
	printf("X: %X\n", decimalNumber);
	ft_printf("x: %x\n", decimalNumber);
//	printf("X: %X\n", 0);

}

////
/*
int	ft_printf(const char *format, ...)
{
	int	return_value;
	int	i;

	i = 0;
	va_list args;
	va_start(args, format);


	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == 'd')
		{
			int arg = va_arg(args, int);
			char char_arg = (char)arg;
			write(1, &char_arg, sizeof(char));
			i = i + 2;
		}
		else
		{
		write (1, &format[i], 1);
		i++;
		}
	}

	va_end(args);
	//ft_strlen(return_value);
	return (return_value);
}
*/
