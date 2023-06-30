/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:39:27 by chbuerge          #+#    #+#             */
/*   Updated: 2023/06/30 16:37:52 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h> //for variadic functions
#include <stdio.h>
#include <unistd.h>



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
/*
char	ft_identify_input_specifier(va_list args, const char format);
{
	if (c == 'c')
		ft_putchar(c);
	else
		write(1, "else", 5);

}*/

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		ft_print_char(s[i]);
		i++;
	}
	return(i);
}
// count the numbers somehow?
void	put_num(char n)
{
	write(1, &n, 1);
}

int	ft_print_nbr(int nb)
{
	int i;

	i = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_print_nbr(-nb);
	}
	else if (nb > 9)
	{
		ft_print_nbr(nb / 10);
		ft_print_nbr(nb % 10);
	}
	else
		put_num(nb + 48);
	return (i);
}



int ft_eval_specifier(va_list args, const char specifier)
 {
	int	length;

	length = 0;
	if (specifier == 'c')
		length = length + ft_print_char(va_arg(args, int));
	else if(specifier == 's')
		length = length + ft_print_str(va_arg(args, char *));
	/*else if (specifier == 'p')
	//...*/
	else if (specifier == 'd')
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
	printf("length: %d\n", length);
	return (length);
}

int main()
{
	ft_printf("%%hello %c %s %d \n", 'o', "wo", 42);
	ft_printf("%d", 421);
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
