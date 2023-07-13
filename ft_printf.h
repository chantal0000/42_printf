/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:00:45 by chbuerge          #+#    #+#             */
/*   Updated: 2023/07/13 13:41:47 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
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
int	ft_print_char(char c);
int	ft_print_str(char *s);
int	ft_print_nbr(int nb);
int	ft_print_u_nbr(unsigned int nb);
int	ft_print_hex(unsigned long int nb, const char format);
int	ft_put_hex(unsigned int nb, char specifier);
int	ft_print_p(unsigned long long ptr);

#endif
