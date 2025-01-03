/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_putptr_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:00:57 by hsacr             #+#    #+#             */
/*   Updated: 2024/12/11 23:06:38 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_printf.h"

int	fn_putptr_length(void *pointer, int *error, t_flags mystruct)
{
	size_t	ptr;
	int		ptr_size;
	int		length;

	ptr = (size_t)pointer;
	if (ptr == 0)
		return (fn_putstr_length("(nil)", error, mystruct));
	length = 0;
	ptr_size = 2 + fn_length(ptr, 16);
	while (mystruct.minimum_width > length + ptr_size)
		length += fn_putchar(' ', mystruct.error);
	length += fn_putstr("0x", mystruct.error);
	length += fn_puthexptr(ptr, fn_tolower, error);
	return (length);
}
