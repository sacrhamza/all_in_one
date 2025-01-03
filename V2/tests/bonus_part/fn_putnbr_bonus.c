/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:00:54 by hsacr             #+#    #+#             */
/*   Updated: 2025/01/03 17:16:19 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_printf_bonus.h"

int	fn_putnbr(int number, int *error)
{
	char	*ptr;
	int		length;

	if (*error == -1)
		return (-1);
	ptr = fn_itoa(number);
	length = fn_putstr(ptr, error);
	free(ptr);
	return (length);
}
