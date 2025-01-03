/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_putptr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:00:57 by hsacr             #+#    #+#             */
/*   Updated: 2025/01/03 17:16:28 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_printf_bonus.h"

int	fn_putptr(void *pointer, int *error)
{
	size_t	ptr;
	int		length;

	if (pointer == NULL)
		return (fn_putstr("(nil)", error));
	ptr = (size_t)pointer;
	length = fn_putstr("0x", error);
	length += fn_puthexptr(ptr, fn_tolower, error);
	return (length);
}
