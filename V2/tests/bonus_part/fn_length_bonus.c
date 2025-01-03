/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:55:35 by hsacr             #+#    #+#             */
/*   Updated: 2025/01/03 16:42:30 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_printf_bonus.h"

int	fn_length(size_t number, size_t base)
{
	int	length;

	length = 1;
	while (number >= base)
	{
		number = number / base;
		length++;
	}
	return (length);
}
