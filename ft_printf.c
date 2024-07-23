/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:37:52 by rohta             #+#    #+#             */
/*   Updated: 2024/07/22 12:02:20 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_free(t_params *params)
{
	free(params->flags);
	free(params->width);
	free(params->precision);
	free(params->converted);
	free(params);
}

static size_t	ft_printf_write(t_params *params)
{
	size_t	byte;

	byte = 0;
	if (ft_strchr("cs", params->specifier))
		byte += ft_write_string(params);
	else if (ft_strchr("di", params->specifier))
		byte += ft_write_number(params);
	else if (ft_strchr("xX", params->specifier))
		byte += ft_write_hex(params);
	else if (params->specifier == 'u')
		byte += ft_write_unsigned(params);
	else if (params->specifier == 'p')
		byte += ft_write_pointer(params);
	else if (params->specifier == '%')
		byte += write(STDOUT_FD, "%", sizeof(char));
	else if (byte == 0)
		return (PRINTF_NULL);
//	if (params->specifier != '%')
//		va_arg(*args, int);
	ft_printf_free(params);
	return (byte);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	size_t		byte;
	t_params	*params;

	byte = 0;
	params = NULL;
	if (!format)
		return (PRINTF_NULL);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			params = ft_calloc(1, sizeof(t_params));
			format = ft_printf_check(params, (char *)format, args);
			byte += ft_printf_write(params);
		}
		else
		{
			byte += write(STDOUT_FD, format, sizeof(char));
			format++;
		}
	}
	va_end(args);
	return (byte);
}
