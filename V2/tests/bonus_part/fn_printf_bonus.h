/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:35:53 by hsacr             #+#    #+#             */
/*   Updated: 2025/01/03 18:43:47 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FN_PRINTF_BONUS_H
# define FN_PRINTF_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

typedef struct fn_flags_st
{
	int		minimum_width;
	int		right_justified;
	char	zero_padding;
	int		dot_flag;
	int		dot_width;
	int		*error;
}	t_flags;

int		fn_putchar(char c, int *error);
int		fn_putstr(char *str, int *error);
char	*fn_itoa(int n);
int		fn_putnbr(int number, int *error);
int		fn_tolower(int c);
int		fn_toupper(int c);
int		fn_puthex(unsigned int n, int (*f)(int), int *error);
int		fn_puthex_length(unsigned int n, int (*f)(int),
			int *error, t_flags mystruct);
int		fn_puthexptr(size_t n, int (*f)(int), int *error);
int		fn_putus(unsigned int n, int *error);
int		fn_putptr(void *pointer, int *error);
int		fn_isdigit(int c);
int		fn_length(size_t number, size_t base);
int		fn_global(char c, va_list args, int *error);
int		fn_flags(char **format, unsigned int index, va_list args, int *error);
int		fn_flag_plus_space(char **format, unsigned int index,
			va_list args, int *error);
int		fn_flag_hash(char **format, unsigned int index,
			va_list args, int *error);
int		fn_strlen(const char *s);
int		fn_print_flags(struct fn_flags_st my_struct, char c,
			int length, va_list args);
int		fn_flags_section(char **format, unsigned int index,
			va_list args, int *error);
int		ft_itoa_length(long number);
int		fn_atoi(const char *nptr, int *error);

int		fn_global_length(char c, va_list args,
			int *there_is_an_error, t_flags mystruct);
int		fn_putstr_length(char *str, int *error, t_flags mystruct);
int		fn_putchar_length(char c, int *error, t_flags mystruct);
int		ft_printf(char *str, ...);
int		fn_putptr_length(void *pointer, int *error, t_flags mystruct);
int		fn_putnbr_length(int number, int *error, t_flags mystruct);
int		fn_putus_length(unsigned int n, int *error, t_flags mystruct);
int		fn_fn(char c, int n, int *error);
#endif
