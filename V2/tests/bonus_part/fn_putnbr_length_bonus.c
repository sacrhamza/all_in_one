/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_putnbr_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:00:54 by hsacr             #+#    #+#             */
/*   Updated: 2025/01/03 16:41:41 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_printf_bonus.h"

static int	fn_putnbr_dot(char *number, int *error, t_flags mystruct)
{
	int	spaces;
	int	length;
	int	cia;

	length = 0;
	cia = number[0] == '-' && mystruct.dot_width >= fn_strlen(number);
	spaces = mystruct.minimum_width - mystruct.dot_width
		* (mystruct.dot_width >= fn_strlen(number)) - fn_strlen(number)
		* (mystruct.dot_width < fn_strlen(number)) - cia;
	if (!mystruct.right_justified)
		length += fn_fn(' ', spaces, error);
	if (cia)
		length += fn_putchar('-', error);
	length += fn_fn('0', mystruct.dot_width - fn_strlen(number + cia), error);
	length += fn_putstr(number + cia, error);
	if (mystruct.right_justified)
		length += fn_fn(' ', spaces, error);
	return (free(number), number = NULL, length);
}

int	fn_putnbr_length(int number, int *error, t_flags mystruct)
{
	char	*ptr;
	int		length;
	int		cia;

	if (*error == -1)
		return (-1);
	if (number == 0 && mystruct.dot_flag && !mystruct.dot_width)
		return (fn_putstr_length("", error, mystruct));
	ptr = fn_itoa(number);
	length = 0;
	if (mystruct.dot_flag)
		return ((fn_putnbr_dot(ptr, error, mystruct)));
	cia = number < 0 && mystruct.zero_padding == '0';
	if (cia)
		length += fn_putchar('-', error);
	while (mystruct.minimum_width > length + fn_strlen(ptr + cia))
		length += fn_putchar(mystruct.zero_padding, error);
	length += fn_putstr(ptr + cia, error);
	free(ptr);
	return (length);
}
