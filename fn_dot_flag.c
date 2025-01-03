/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_dot_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:55:11 by hsacr             #+#    #+#             */
/*   Updated: 2024/12/11 18:04:13 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	fn_dot_flag(size_t number, int *spaces, fn_flags_t mystruct, int base)
{
	int	spaces;
	int	length;

	length = 0;
	spaces = mystruct.minimum_width - mystruct.dot_width
		* (mystruct.dot_width > fn_strlen(number)) - fn_strlen(number)
		* (mystruct.dot_width < fn_length(number, base));
	if (!mystruct.right_justified)
		length += fn_fn(mystruct.zero_padding, spaces, error);
	while (mystruct.dot_width > fn_length(number, base))
	{
		length += fn_putchar('0', error);
		mystruct.dot_width--;
	}
	length += fn_putstr(number, error);
	if (mystruct.right_justified)
		length += fn_fn(' ', spaces, error);
	return (length);
}
