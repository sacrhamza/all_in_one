/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:55:35 by hsacr             #+#    #+#             */
/*   Updated: 2024/12/11 18:51:56 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_printf.h"

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
