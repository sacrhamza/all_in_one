/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_putchar_length.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:50:40 by hsacr             #+#    #+#             */
/*   Updated: 2024/12/11 23:06:14 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_printf.h"

int	fn_putchar_length(char c, int *error, t_flags mystruct)
{
	int	length;

	length = 0;
	if (*error == -1)
		return (-1);
	while (mystruct.minimum_width > 1 + length)
		length += fn_putchar(' ', error);
	length += fn_putchar(c, error);
	return (length);
}
