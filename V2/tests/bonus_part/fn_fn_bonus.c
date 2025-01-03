/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_fn_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:59:27 by hsacr             #+#    #+#             */
/*   Updated: 2025/01/03 17:31:20 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_printf_bonus.h"

int	fn_fn(char c, int n, int *error)
{
	int	length;

	length = 0;
	while (length < n)
	{
		length += fn_putchar(c, error);
		if (*error == -1)
			return (*error);
	}
	return (length);
}
