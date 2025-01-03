/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_putstr_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:19:00 by hsacr             #+#    #+#             */
/*   Updated: 2024/12/11 23:06:43 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_printf.h"

int	mystrlen(const char *str)
{
	if (str == NULL)
		return (6);
	return (fn_strlen(str));
}

static int	fn_putstr_dot(char *str, int *error, t_flags mystruct);

int	print_str(char *str, int str_length, int *error, t_flags mystruct)
{
	int	length;

	length = 0;
	if (str == NULL && mystruct.dot_width >= 6)
	{
		mystruct.dot_width = 6;
		mystruct.minimum_width = 0;
		return (fn_putstr("(null)", error));
	}
	else if (str == NULL)
		return (0);
	while (str_length > length && *str)
		length += fn_putchar(*str++, error);
	return (length);
}

static int	fn_putstr_dot(char *str, int *error, t_flags mystruct)
{
	int	spaces;
	int	length;
	int	str_length;

	str_length = mystrlen(str) * (mystrlen(str) <= mystruct.dot_width)
		+ mystruct.dot_width * (mystrlen(str) > mystruct.dot_width);
	spaces = mystruct.minimum_width - (str_length)
		* (str != 0 || mystruct.dot_width >= 6);
	length = 0;
	spaces += length;
	if (!mystruct.right_justified)
		length += fn_fn(' ', spaces, error);
	length += print_str(str, str_length, error, mystruct);
	if (mystruct.right_justified)
		length += fn_fn(' ', spaces, error);
	return (length);
}

int	fn_putstr_length(char *str, int *error, t_flags mystruct)
{
	int	length;

	length = 0;
	if (mystruct.dot_flag)
		return (fn_putstr_dot(str, error, mystruct));
	if (str == NULL)
		return (fn_putstr_length("(null)", error, mystruct));
	length += fn_fn(' ', mystruct.minimum_width - fn_strlen(str), error);
	while (*str)
	{
		length += fn_putchar(*str, error);
		if (*error == -1)
			return (-1);
		str++;
	}
	return (length);
}
