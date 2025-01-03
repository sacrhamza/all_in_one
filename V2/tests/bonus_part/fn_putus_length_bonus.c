/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_putus_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:36:48 by hsacr             #+#    #+#             */
/*   Updated: 2025/01/03 16:43:35 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_printf_bonus.h"

static int	fn_putus_dot(unsigned int number, int *error, t_flags mystruct)
{
	int	spaces;
	int	length;

	length = 0;
	spaces = mystruct.minimum_width - mystruct.dot_width
		* (mystruct.dot_width >= fn_length(number, 10)) - fn_length(number, 10)
		* (mystruct.dot_width < fn_length(number, 10));
	if (!mystruct.right_justified)
		length += fn_fn(' ', spaces, error);
	length += fn_fn('0', mystruct.dot_width - fn_length(number, 10), error);
	length += fn_putus(number, error);
	if (mystruct.right_justified)
		length += fn_fn(' ', spaces, error);
	return (length);
}

int	fn_putus_length(unsigned int n, int *error, t_flags mystruct)
{
	int	length;

	if (*error == -1)
		return (-1);
	if (n == 0 && mystruct.dot_flag && !mystruct.dot_width)
		return (fn_putstr_length("", error, mystruct));
	length = 0;
	if (mystruct.dot_flag)
		return (fn_putus_dot(n, error, mystruct));
	while (mystruct.minimum_width > fn_length(n, 10) + length)
		length += fn_putchar(mystruct.zero_padding, error);
	length += fn_putus(n, error);
	return (length);
}
