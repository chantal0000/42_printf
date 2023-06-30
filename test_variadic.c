/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_variadic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:28:19 by chbuerge          #+#    #+#             */
/*   Updated: 2023/06/29 15:38:49 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// EXAMPLE VARIADIC FUNCTION

#include <stdarg.h> //for variadic functions
#include <stdio.h> 


int	sum(int num_args, ...)
{
	int total;
	int i;

	i = 0;
	total = 0;
	va_list	args; //hold information about the variable arguments
	va_start(args, num_args); //marco initializes the va_list object, allow access the variable argument

	while (i < num_args)
	{
		int arg = va_arg(args, int);
		total = total + arg;
		i++;
	}
va_end(args);
return (total);
}

int main ()
{
	int result = sum(2, -1, 20);
	printf("Summe: %d\n", result);
	return (0);
}
