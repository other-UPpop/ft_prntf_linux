/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 02:52:40 by rohta             #+#    #+#             */
/*   Updated: 2024/05/19 19:07:22 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*new_str;
	unsigned char	uc;

	new_str = NULL;
	uc = c;
	while (*s)
	{
		if (*s == uc)
			new_str = s;
		s++;
	}
	if (uc == '\0')
		return ((char *)s);
	if (new_str)
		return ((char *)new_str);
	return (NULL);
}
