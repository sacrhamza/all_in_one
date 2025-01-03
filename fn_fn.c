/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_fn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:59:27 by hsacr             #+#    #+#             */
/*   Updated: 2024/12/09 13:29:40 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_printf.h"

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
