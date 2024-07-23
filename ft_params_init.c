/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:13:36 by rohta             #+#    #+#             */
/*   Updated: 2024/06/30 19:26:27 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_init_mods(ssize_t *width, ssize_t *precision)
{
	*width = NOT_SPEC;
	*precision = NOT_SPEC;
}

static void	ft_init_flags(t_flags *flags)
{
	flags->flag_minus = false;
	flags->flag_plus = false;
	flags->flag_space = false;
	flags->flag_zero = false;
	flags->flag_hashtag = false;
}

void	ft_init_params(t_params *params)
{
	params->flags = ft_calloc(1, sizeof(t_flags));
	params->width = ft_calloc(1, sizeof(ssize_t));
	params->precision = ft_calloc(1, sizeof(ssize_t));
	params->dot = false;
	ft_init_flags(params->flags);
	ft_init_mods(params->width, params->precision);
}
