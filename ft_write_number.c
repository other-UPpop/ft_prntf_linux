/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:19:03 by rohta             #+#    #+#             */
/*   Updated: 2024/07/18 20:22:01 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_write_flags(t_params *params, size_t *print_len,
		size_t *conv_len, int *number)
{
	bool	plus_space;
	size_t	byte;

	byte = 0;
	plus_space = (params->flags->flag_plus || params->flags->flag_space);
	if (*number < 0 && *params->converted != '0')
	{
		byte += write(STDOUT_FD, "-", sizeof(char));
		if (0 < *print_len)
			--(*print_len);
		--(*conv_len);
		params->converted = ft_substr(params->converted, 1,
				(size_t)conv_len);
	}
	else if (plus_space && 0 <= *number)
	{
		if (((*number < 0 && params->flags->flag_minus)
				|| (!params->flags->flag_zero)) && (0 < *print_len))
			--(*print_len);
		if (params->flags->flag_plus)
			byte += write(STDOUT_FD, "+", sizeof(char));
		else
			byte += write(STDOUT_FD, " ", sizeof(char));
	}
	return (byte);
}

static	void	ft_print_len(t_params *params, bool plus_space,
		int number, size_t *print_len)
{
	if ((plus_space && number < 0 && 0 < *print_len)
		|| (plus_space && 0 < *print_len && !params->flags->flag_minus))
		--(*print_len);
}

static size_t	ft_write_int(t_params *params, size_t put_prec,
		size_t print_len, size_t conv_len)
{
	size_t	byte;
	bool	plus_space;
	int		number;

	byte = 0;
	plus_space = (params->flags->flag_plus || params->flags->flag_space);
	number = ft_atoi(params->converted);
	if (params->flags->flag_minus)
	{
		byte += ft_write_flags(params, &print_len, &conv_len, &number);
		byte += ft_write_prec(params, put_prec, &print_len, conv_len);
		ft_print_len(params, plus_space, number, &print_len);
		byte += ft_write_width(params, put_prec, conv_len, &print_len);
	}
	else
	{
		if (ft_zero_check(params) == 1)
			byte += ft_write_flags(params, &print_len, &conv_len, &number);
		ft_print_len(params, plus_space, number, &print_len);
		byte += ft_write_width(params, put_prec, conv_len, &print_len);
		if (ft_zero_check(params) == 0)
			byte += ft_write_flags(params, &print_len, &conv_len, &number);
		byte += ft_write_prec(params, put_prec, &print_len, conv_len);
	}
	return (byte);
}

static void	ft_check_flag(t_params *params)
{
	if (params->flags->flag_minus || *params->precision != NOT_SPEC)
		params->flags->flag_zero = false;
	if (params->flags->flag_plus)
		params->flags->flag_space = false;
}

size_t	ft_write_number(t_params *params)
{
	ssize_t	conv_len;
	size_t	print_len;
	size_t	put_prec;
	int		number;

	print_len = 0;
	put_prec = 0;
	conv_len = ft_strlen(params->converted);
	number = ft_atoi(params->converted);
	ft_check_flag(params);
	print_len = *params->width;
	ft_prec_dot(params, &print_len, &put_prec, number);
	if (conv_len < *params->width && number < 0
		&& (params->flags->flag_plus || params->flags->flag_space))
		++print_len;
	ft_conv_prec(params, conv_len, &put_prec, &print_len);
	if (*params->precision == 0 && number == 0)
		conv_len = 0;
	else if (number < 0 && ((ssize_t)conv_len - 1 < *params->precision)
		&& *params->width > *params->precision)
		++put_prec;
	return (ft_write_int(params, put_prec, print_len, conv_len));
}
