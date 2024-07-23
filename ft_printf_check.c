/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:08:58 by rohta             #+#    #+#             */
/*   Updated: 2024/07/18 16:07:47 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_apply_args(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_apply_character(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_apply_string(va_arg(args, char *)));
	else if (specifier == 'p')
		return (ft_apply_pointer(va_arg(args, size_t)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_apply_desimals(va_arg(args, int), 10, DESIMALS));
	else if (specifier == 'u')
		return (ft_apply_hex(va_arg(args, unsigned int), 10, DESIMALS));
	else if (specifier == 'x')
		return (ft_apply_hex(va_arg(args, unsigned int), 16, LOW_HEX));
	else if (specifier == 'X')
		return (ft_apply_hex(va_arg(args, unsigned int), 16, UP_HEX));
	else if (specifier == '%')
		return (ft_apply_character(specifier));
	return (NULL);
}

static	void	ft_precision(t_params *params, ssize_t **mod, size_t *index)
{
	params->dot = true;
	*mod = (params->precision);
	**mod = 0;
	++(*index);
}

static	char	*ft_check_mods(char *format, t_params *params)
{
	char	*tmp;
	size_t	index;
	size_t	start;
	ssize_t	*mod;

	index = 0;
	mod = params->width;
	while ((ft_isdigit(format[index]) || format[index] == '.'))
	{
		if (format[index] == '.')
			ft_precision(params, &mod, &index);
		start = index;
		while (ft_isdigit(format[index]))
			++index;
		if (index > start)
		{
			tmp = ft_substr(format, start, index - start);
			if (tmp)
			{
				*mod = ft_atoi(tmp);
				free(tmp);
			}
		}
	}
	return (format + index);
}

static char	*ft_check_flags(char *format, t_flags *flags)
{
	while (ft_strchr(FLAGS, *format))
	{
		if (*format == '-')
			flags->flag_minus = true;
		else if (*format == '+')
			flags->flag_plus = true;
		else if (*format == ' ')
			flags->flag_space = true;
		else if (*format == '0')
			flags->flag_zero = true;
		else if (*format == '#')
			flags->flag_hashtag = true;
		++format;
	}
	return (format);
}

char	*ft_printf_check(t_params *params, char *format, va_list args)
{
	ft_init_params(params);
	format = ft_check_flags(++format, params->flags);
	format = ft_check_mods(format, params);
	params->specifier = *format;
	params->converted = ft_apply_args(params->specifier, args);
	return (++format);
}
