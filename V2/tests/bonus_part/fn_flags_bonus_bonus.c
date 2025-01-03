/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:41:08 by hsacr             #+#    #+#             */
/*   Updated: 2025/01/03 16:38:43 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_printf_bonus.h"

int	fn_flags_check(char c)
{
	if (c == '0' || c == '-' || c == '.' || fn_isdigit(c))
		return (1);
	return (0);
}

int	fn_flags(char **format, unsigned int index, va_list args, int *error)
{
	int	length;

	if (format[0][index] == '#')
		return (fn_flag_hash(format, index, args, error));
	else if (format[0][index] == '+' || format[0][index] == ' ')
		return (fn_flag_plus_space(format, index, args, error));
	else if (fn_flags_check(format[0][index]))
		return (fn_flags_section(format, index, args, error));
	else
	{
		length = fn_global(format[0][index], args, error);
		format[0] += 1;
		return (length);
	}
	return (0);
}
