/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_flag_hash_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:27:52 by hsacr             #+#    #+#             */
/*   Updated: 2025/01/03 17:30:50 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_printf_bonus.h"

int	fn_flag_hash(char **format, unsigned int index, va_list args, int *error)
{
	unsigned int	number;
	int				length;

	length = 0;
	if (fn_tolower(format[0][index + 1]) == 'x')
	{
		number = va_arg(args, unsigned int);
		if (number != 0)
		{
			length += fn_putchar('0', error);
			length += fn_putchar(format[0][index + 1], error);
		}
		if (format[0][index + 1] == 'x')
			length += fn_puthex(number, fn_tolower, error);
		else
			length += fn_puthex(number, fn_toupper, error);
		format[0] += 2;
	}
	else if (format[0][index + 1] != '\0')
	{
		length = fn_global(format[0][index + 1], args, error);
		format[0] += 2;
	}
	return (length);
}
