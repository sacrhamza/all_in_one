/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:35:21 by hsacr             #+#    #+#             */
/*   Updated: 2024/12/08 17:53:14 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_printf.h"

int	ft_printf(char *format, ...)
{
	int		length;
	int		i;
	va_list	args;
	int		there_is_an_error;

	there_is_an_error = 0;
	i = 0;
	length = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
			length += fn_flags(&format, i + 1, args, &there_is_an_error);
		else if (format[i] != '\0')
			length += fn_putchar(format[i], &there_is_an_error);
		i++;
		if (there_is_an_error == -1)
			return (there_is_an_error);
	}
	return (length);
}
