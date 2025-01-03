/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_flags_section_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:55:20 by hsacr             #+#    #+#             */
/*   Updated: 2025/01/03 12:31:26 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_printf.h"

int	fn_print_flags(struct fn_flags_st mystruct, char c,
		int length, va_list args)
{
	if (mystruct.dot_flag)
		length += fn_global_length(c, args, mystruct.error, mystruct);
	else if (mystruct.minimum_width && mystruct.right_justified)
	{
		length += fn_global(c, args, mystruct.error);
		length += fn_fn(' ', mystruct.minimum_width - length, mystruct.error);
	}
	else if (mystruct.minimum_width)
		length += fn_global_length(c, args, mystruct.error, mystruct);
	else
		length += fn_global(c, args, mystruct.error);
	return (length);
}

static void	fn_dot_flag_bonus(char **format,
		t_flags *mystruct, unsigned int index)
{
	mystruct->dot_flag = 1;
	if (fn_isdigit(format[0][index + 1]))
	{
		mystruct->dot_width = fn_atoi(format[0] + index + 1, mystruct->error);
		if (*(mystruct->error) == -1)
			return ;
		format[0] += ft_itoa_length(mystruct->dot_width);
	}
}

static void	fn_width_flag_bonus(char **format,
		t_flags *mystruct, unsigned int index)
{
	mystruct->minimum_width = fn_atoi(format[0] + index, mystruct->error);
	if (*(mystruct->error) == -1)
		return ;
	format[0] += ft_itoa_length(mystruct->minimum_width) - 1;
}

static void	fn_flag_bonus(char **format, t_flags *mystruct, unsigned int index)
{
	while (1)
	{
		if (format[0][index] == '0')
			mystruct->zero_padding = '0';
		else if (format[0][index] == '-')
			mystruct->right_justified = 1;
		else if (fn_isdigit(format[0][index]))
			fn_width_flag_bonus(format, mystruct, index);
		else if (format[0][index] == '.')
			fn_dot_flag_bonus(format, mystruct, index);
		else
			break ;
		format[0] += 1;
	}
}

int	fn_flags_section(char **format, unsigned int index,
		va_list args, int *error)
{
	int		length;
	t_flags	mystruct;

	mystruct = (t_flags){0, 0, ' ', 0, 0, error};
	length = 0;
	fn_flag_bonus(format, &mystruct, index);
	if (*error == -1)
		return (*error);
	if (format[0][index] != 0)
	{
		length = (fn_print_flags(mystruct, format[0][index], length, args));
		format[0] += 1;
	}
	return (length);
}
