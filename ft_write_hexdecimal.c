/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hexdecimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:01:37 by rohta             #+#    #+#             */
/*   Updated: 2024/07/18 15:39:38 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_write_flags(t_params *params, size_t *print_len)
{
	size_t	byte;

	byte = 0;
	if (params->flags->flag_hashtag && *params->converted != '0')
	{
		if (2 <= *print_len)
			*print_len -= 2;
		if (params->specifier == 'x')
			byte += write(STDOUT_FD, "0x", 2);
		else
			byte += write(STDOUT_FD, "0X", 2);
		if (*params->converted == '0'
			&& (!params->flags->flag_zero || !params->flags->flag_minus))
			--(*print_len);
	}
	return (byte);
}

static	size_t	ft_minus_flag(t_params *params, ssize_t put_prec,
		size_t print_len, size_t conv_len)
{
	size_t	byte;
	size_t	i;

	byte = 0;
	i = 0;
	byte += ft_write_flags(params, &print_len);
	while ((ssize_t)i++ < put_prec)
		byte += write(STDOUT_FD, "0", 1);
	while (put_prec-- && 0 <= put_prec && 0 < print_len)
		--print_len;
	byte += write(STDOUT_FD, params->converted, conv_len);
	while (conv_len < print_len--)
		byte += write(STDOUT_FD, " ", 1);
	return (byte);
}

static	size_t	ft_not_minus(t_params *params, ssize_t put_prec,
		size_t print_len, size_t conv_len)
{
	size_t	byte;
	size_t	i;
	char	c;

	byte = 0;
	i = 0;
	c = ' ';
	if (params->flags->flag_zero)
		c = '0';
	if (params->flags->flag_zero && params->flags->flag_hashtag)
		byte += ft_write_flags(params, &print_len);
	else if (params->flags->flag_hashtag && *params->converted != '0'
		&& (ssize_t)conv_len < *params->width && 2 < print_len)
		print_len -= 2;
	while (put_prec + conv_len < print_len--)
		byte += write(STDOUT_FD, &c, sizeof(char));
	if (put_prec != 0 && params->flags->flag_hashtag)
		byte += ft_write_flags(params, &print_len);
	while ((ssize_t)i++ < put_prec)
		byte += write(STDOUT_FD, "0", 1);
	if (!(params->flags->flag_zero) && put_prec == 0)
		byte += ft_write_flags(params, &print_len);
	byte += write(STDOUT_FD, params->converted, conv_len);
	return (byte);
}

static size_t	ft_write_xp(t_params *params, ssize_t put_prec,
		size_t print_len)
{
	size_t	conv_len;
	size_t	byte;

	byte = 0;
	conv_len = ft_strlen(params->converted);
	if (*params->precision <= 0 && params->dot)
	{
		if (*params->width <= 0)
			print_len = 0;
		if (*params->converted == '0')
			conv_len = 0;
	}
	if (params->flags->flag_minus)
		byte += ft_minus_flag(params, put_prec, print_len, conv_len);
	else
		byte += ft_not_minus(params, put_prec, print_len, conv_len);
	return (byte);
}

size_t	ft_write_hex(t_params *params)
{
	ssize_t	conv_len;
	size_t	print_len;
	size_t	put_prec;

	conv_len = ft_strlen(params->converted);
	print_len = *params->width;
	if (*params->width <= *params->precision)
		print_len = *params->precision;
	put_prec = 0;
	if (conv_len < *params->precision)
		put_prec = *params->precision - conv_len;
	if (params->flags->flag_minus || *params->precision != NOT_SPEC)
		params->flags->flag_zero = false;
	params->flags->flag_space = false;
	params->flags->flag_plus = false;
	if (*params->width <= conv_len && *params->precision <= conv_len)
	{
		print_len = conv_len;
		put_prec = 0;
	}
	return (ft_write_xp(params, put_prec, print_len));
}
