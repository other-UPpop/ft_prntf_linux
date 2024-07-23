/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:37:14 by rohta             #+#    #+#             */
/*   Updated: 2024/07/22 10:10:41 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef PRINTFF_NULL
#  define PRINTF_NULL -1
# endif

# ifndef STDOUT_FD
#  define STDOUT_FD 1
# endif

# ifndef NOT_SPEC
#  define NOT_SPEC -1
# endif

# ifndef FLAGS
#  define FLAGS "-+ 0#"
# endif

# ifndef DESIMALS
#  define DESIMALS "0123456789"
# endif

# ifndef LOW_HEX
#  define LOW_HEX "0123456789abcdef"
# endif

# ifndef UP_HEX
#  define UP_HEX "0123456789ABCDEF"
# endif

typedef struct s_flags
{
	bool	flag_minus;
	bool	flag_plus;
	bool	flag_space;
	bool	flag_zero;
	bool	flag_hashtag;
}	t_flags;

typedef struct s_params
{
	t_flags	*flags;
	ssize_t	*width;
	ssize_t	*precision;
	char	*converted;
	char	specifier;
	bool	dot;
}	t_params;

int		ft_printf(const char *format, ...);
char	*ft_printf_check(t_params *params, char *format, va_list args);
void	ft_init_params(t_params *params);
char	*ft_apply_character(int arg);
char	*ft_apply_string(char *arg);
char	*ft_apply_pointer(size_t arg);
char	*ft_apply_desimals(long long arg, size_t base_len, char *base);
char	*ft_apply_hex(unsigned long long arg, size_t base_len, char *base);
size_t	ft_write_number(t_params *params);
size_t	ft_write_unsigned(t_params *params);
size_t	ft_write_hex(t_params *params);
ssize_t	ft_write_string(t_params *params);
size_t	ft_write_pointer(t_params *params);
int		ft_zero_check(t_params *params);
size_t	ft_write_prec(t_params *params, size_t put_prec, size_t *print_len,
			size_t conv_len);
size_t	ft_write_width(t_params *params, size_t put_prec, size_t conv_len,
			size_t *print_len);
void	ft_conv_prec(t_params *params, ssize_t conv_len, size_t *put_prec,
			size_t *print_len);
void	ft_prec_dot(t_params *params, size_t *print_len, size_t *put_prec,
			int number);

#endif
