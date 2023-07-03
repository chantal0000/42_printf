/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:39:27 by chbuerge          #+#    #+#             */
/*   Updated: 2023/07/03 14:22:27 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
/*
char	ft_identify_input_specifier(va_list args, const char format);
{
	if (c == 'c')
		ft_putchar(c);
	else
		write(1, "else", 5);

}*/





int	ft_eval_specifier(va_list args, const char specifier)
 {
	int	length;

	length = 0;
	if (specifier == 'c')
		length = length + ft_print_char(va_arg(args, int));
	else if(specifier == 's')
		length = length + ft_print_str(va_arg(args, char *));
	/*else if (specifier == 'p')
	//...*/
	else if (specifier == 'd' || specifier == 'i')
		length = length + ft_print_nbr(va_arg(args, int));
	/*
	else if (specifier == 'i')
	//...
	else if (specifier == 'u')
	//...
	else if (specifier == 'x')
	//...
	else if (specifier == 'X')
	//...*/
	else if (specifier == '%')
	length = length + ft_print_char('%');
	else
		return (0);
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

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			length = length + ft_eval_specifier(args, format[i]);
			i++;
		}
		else
		{
			length = length + ft_print_char(format[i]);

		i++;
		}
	}
	va_end(args);
	/// ALARM DELTE PRINTF
	printf("length: %d\n", length);
	return (length);
}

/* MAIN FUNCTION */


int main()
{
	ft_printf("char c: hello %c\n", 'o');
	ft_printf("int i 421: %i\n", 421);
	ft_printf("int d -42: %d\n", -42);
	ft_printf("percent: %% hello\n");
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
