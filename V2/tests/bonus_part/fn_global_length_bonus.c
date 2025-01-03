/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_global_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:23:17 by hsacr             #+#    #+#             */
/*   Updated: 2025/01/03 16:42:25 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_printf_bonus.h"

int	fn_global_length(char c, va_list args, int *error, t_flags mystruct)
{
	int	length;

	length = 0;
	if (c == 'c')
		length = fn_putchar_length(va_arg(args, int), error, mystruct);
	else if (c == 's')
		length = fn_putstr_length(va_arg(args, char *), error, mystruct);
	else if (c == 'p')
		length = fn_putptr_length(va_arg(args, void *), error, mystruct);
	else if (c == 'd' || c == 'i')
		length = fn_putnbr_length(va_arg(args, int), error, mystruct);
	else if (c == 'u')
		length = fn_putus_length(va_arg(args, unsigned int), error, mystruct);
	else if (c == 'x')
		length += fn_puthex_length(va_arg(args, unsigned int),
				fn_tolower, error, mystruct);
	else if (c == 'X')
		length += fn_puthex_length(va_arg(args, unsigned int),
				fn_toupper, error, mystruct);
	return (length);
}
