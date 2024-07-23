/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:57:38 by rohta             #+#    #+#             */
/*   Updated: 2024/06/13 15:06:55 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;

	copy = (char *)malloc(ft_strlen(s1) + 1);
	if (copy == NULL)
	{
		return (copy);
	}
	ft_strlcpy(copy, s1, ft_strlen(s1) + 1);
	return (copy);
}
