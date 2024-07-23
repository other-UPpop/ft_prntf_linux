/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:29:51 by rohta             #+#    #+#             */
/*   Updated: 2024/07/18 13:46:00 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_not_minus(t_params *params, size_t print_len,
		size_t put_prec, char c)
{
	size_t	conv_len;
	size_t	byte;
	size_t	i;
	int		sign;

	sign = ft_atoi(params->converted);
	conv_len = ft_strlen(params->converted);
	if (*params->precision == 0 && sign == 0)
		conv_len = 0;
	byte = 0;
	i = 0;
	while (put_prec + conv_len < print_len--)
		byte += write(STDOUT_FD, &c, sizeof(char));
	while (i++ < put_prec)
		byte += write(STDOUT_FD, "0", sizeof(char));
	byte += write(STDOUT_FD, params->converted, conv_len);
	return (byte);
}

static
size_t	ft_write_uns(t_params *params, size_t put_prec, size_t print_len,
		int sign)
{
	size_t	conv_len;
	size_t	byte;
	size_t	i;
	char	c;

	i = 0;
	byte = 0;
	c = ' ';
	if (params->flags->flag_zero && *params->precision == NOT_SPEC)
		c = '0';
	if (params->flags->flag_minus)
	{
		conv_len = ft_strlen(params->converted);
		if (*params->precision == 0 && sign == 0)
			conv_len = 0;
		while (i++ < put_prec && print_len--)
			byte += write(STDOUT_FD, "0", sizeof(char));
		byte += write(STDOUT_FD, params->converted, conv_len);
		while (conv_len < print_len--)
			byte += write(STDOUT_FD, " ", sizeof(char));
	}
	else
		byte += ft_not_minus(params, print_len, put_prec, c);
	return (byte);
}

static void	ft_check_flag(t_params *params, size_t *put_prec,
		size_t *print_len, int sign)
{
	ssize_t	conv_len;

	conv_len = ft_strlen(params->converted);
	params->flags->flag_plus = false;
	params->flags->flag_space = false;
	if (*params->width < *params->precision)
	{
		*print_len = *params->precision;
		*params->width = 0;
		if (sign < 0 && *print_len == (size_t)conv_len - 1)
			++(*put_prec);
	}
	else
		*print_len = *params->width;
}

size_t	ft_write_unsigned(t_params *params)
{
	ssize_t	conv_len;
	size_t	print_len;
	size_t	put_prec;
	int		sign;

	print_len = 0;
	put_prec = 0;
	sign = ft_atoi(params->converted);
	conv_len = ft_strlen(params->converted);
	ft_check_flag(params, &put_prec, &print_len, sign);
	if (conv_len < *params->precision)
		put_prec = *params->precision - conv_len;
	if (*params->width <= conv_len && *params->precision <= conv_len
		&& *params->precision != 0)
	{
		print_len = conv_len;
		put_prec = 0;
	}
	return (ft_write_uns(params, put_prec, print_len, sign));
}
