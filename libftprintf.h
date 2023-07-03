/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:00:45 by chbuerge          #+#    #+#             */
/*   Updated: 2023/07/03 14:22:21 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
/*write*/
# include <unistd.h>
/* malloc */
# include <stdlib.h>
/* variadic functions */
# include <stdarg.h>
/* include libft */
# include "./libft/libft.h"

/* ft_printf.c */
int	ft_eval_specifier(va_list args, const char specifier);
int	ft_printf(const char *format, ...);

/* ft_printf_utils.c */
int	ft_print_char(int c);
int	ft_print_str(char *s);
int	ft_print_nbr(int nb);

#endif
