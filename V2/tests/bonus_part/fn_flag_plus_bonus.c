/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_flag_plus_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:35:23 by hsacr             #+#    #+#             */
/*   Updated: 2025/01/03 17:31:06 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_printf_bonus.h"

int	fn_flag_plus_space(char **format, unsigned int index,
				va_list args, int *error)
{
	int	length;
	int	number;

	length = 0;
	if (format[0][index + 1] == 'd' || format[0][index + 1] == 'i')
	{
		number = va_arg(args, int);
		if (number >= 0)
			length += fn_putchar(format[0][index], error);
		length += fn_putnbr(number, error);
		format[0] += 2;
	}
	else if (format[0][index + 1] != '\0')
	{
		length = fn_global(format[0][index + 1], args, error);
		format[0] += 2;
	}
	return (length);
}
