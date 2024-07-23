/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_diuxX.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:03:32 by rohta             #+#    #+#             */
/*   Updated: 2024/06/28 21:43:19 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_arg_hex_len(unsigned long long arg, size_t base_len)
{
	size_t	arg_len;

	arg_len = 0;
	if (arg == 0)
	{
		++arg_len;
		return (arg_len);
	}
	while (arg)
	{
		arg /= base_len;
		++arg_len;
	}
	return (arg_len);
}

char	*ft_apply_hex(unsigned long long arg, size_t base_len, char *base)
{
	char	*str;
	size_t	len;

	len = ft_arg_hex_len(arg, base_len);
	str = calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (arg == 0)
		str[--len] = '0';
	else
	{
		while (arg)
		{
			str[--len] = base[arg % base_len];
			arg /= base_len;
		}
	}
	return (str);
	free(str);
}

static size_t	ft_arg_len(long long arg, size_t base_len)
{
	size_t	arg_len;

	arg_len = 0;
	if (arg == 0)
	{
		++arg_len;
		return (arg_len);
	}
	else if (arg < 0)
	{
		arg = -arg;
		++arg_len;
	}
	while (arg)
	{
		arg /= base_len;
		++arg_len;
	}
	return (arg_len);
}

char	*ft_apply_desimals(long long arg, size_t base_len, char *base)
{
	char	*str;
	size_t	len;

	len = ft_arg_len(arg, base_len);
	str = calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (arg < 0)
	{
		str[0] = '-';
		arg = -arg;
	}
	if (arg == 0)
		str[--len] = '0';
	else
	{
		str[len] = '\0';
		while (arg)
		{
			str[--len] = base[arg % base_len];
			arg /= base_len;
		}
	}
	return (str);
}
