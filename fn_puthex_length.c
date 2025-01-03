/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_puthex_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:31:41 by hsacr             #+#    #+#             */
/*   Updated: 2024/12/12 14:47:11 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_printf.h"

static int	fn_puthex_dot(unsigned int number, int *error,
		t_flags mystruct, int (*f)(int))
{
	int	spaces;
	int	length;

	spaces = mystruct.minimum_width - mystruct.dot_width
		* (mystruct.dot_width >= fn_length(number, 16))
		- fn_length(number, 16) * (mystruct.dot_width < fn_length(number, 16));
	length = 0;
	if (!mystruct.right_justified)
		length += fn_fn(' ', spaces, error);
	length += fn_fn('0', mystruct.dot_width - fn_length(number, 16), error);
	length += fn_puthex(number, f, error);
	if (mystruct.right_justified)
		length += fn_fn(' ', spaces, error);
	return (length);
}

int	fn_puthex_length(unsigned int n, int (*f)(int),
		int *error, t_flags mystruct)
{
	int		length;

	if (*error == -1)
		return (-1);
	if (n == 0 && mystruct.dot_flag && !mystruct.dot_width)
		return (fn_putstr_length("", error, mystruct));
	if (mystruct.dot_flag)
		return (fn_puthex_dot(n, error, mystruct, f));
	length = 0;
	while (mystruct.minimum_width > fn_length(n, 16) + length)
		length += fn_putchar(mystruct.zero_padding, error);
	length += fn_puthex(n, f, error);
	return (length);
}
