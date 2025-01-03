/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:55:06 by hsacr             #+#    #+#             */
/*   Updated: 2024/12/08 22:55:07 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_printf.h"

int	fn_atoi(const char *nptr, int *error)
{
	unsigned long long	atoi_result;
	int					atoi_result_sign;

	if (nptr == 0)
		return (0);
	atoi_result = 0;
	atoi_result_sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			atoi_result_sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		atoi_result = atoi_result * 10 + (*(nptr++) - '0');
		if (atoi_result > INT_MAX)
			*error = -1;
	}
	return (atoi_result * atoi_result_sign);
}
