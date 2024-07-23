/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_number_sub.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:03:28 by rohta             #+#    #+#             */
/*   Updated: 2024/07/18 20:21:33 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_write_prec(t_params *params, size_t put_prec,
		size_t *print_len, size_t conv_len)
{
	size_t	i;
	size_t	byte;

	i = 0;
	byte = 0;
	if (params->flags->flag_minus)
	{
		while (i++ < put_prec && (*print_len)--)
			byte += write(STDOUT_FD, "0", sizeof(char));
		byte += write(STDOUT_FD, params->converted, conv_len);
	}
	else
	{
		while (i++ < put_prec)
			byte += write(STDOUT_FD, "0", sizeof(char));
		byte += write(STDOUT_FD, params->converted, conv_len);
	}
	return (byte);
}

int	ft_zero_check(t_params *params)
{
	if (params->flags->flag_zero && *params->precision == NOT_SPEC)
		return (1);
	return (0);
}

size_t	ft_write_width(t_params *params, size_t put_prec,
		size_t conv_len, size_t *print_len)
{
	size_t	byte;
	char	c;

	byte = 0;
	c = ' ';
	if (params->flags->flag_minus)
	{
		while (conv_len < (*print_len)--)
			byte += write(STDOUT_FD, " ", sizeof(char));
	}
	else
	{
		if (ft_zero_check(params) == 1)
			c = '0';
		while (put_prec + conv_len < (*print_len)--)
			byte += write(STDOUT_FD, &c, sizeof(char));
	}
	return (byte);
}

void	ft_conv_prec(t_params *params, ssize_t conv_len,
		size_t *put_prec, size_t *print_len)
{
	if (*params->precision != 0)
	{
		if (*put_prec == 1 || conv_len < *params->precision)
			*put_prec += (*params->precision - conv_len);
		if (*params->width <= conv_len && *params->precision <= conv_len
			&& *put_prec != 1)
		{
			*print_len = conv_len;
			*put_prec = 0;
			*params->width = 0;
		}
	}
}

void	ft_prec_dot(t_params *params, size_t *print_len,
		size_t *put_prec, int number)
{
	ssize_t	conv_len;

	conv_len = ft_strlen(params->converted);
	if (*params->width <= *params->precision && params->dot)
	{
		*print_len = *params->precision;
		if (number < 0)
		{
			if (!params->flags->flag_minus || conv_len < *params->width)
				++(*print_len);
			if (0 < *params->precision)
				++(*put_prec);
		}
	}
}
