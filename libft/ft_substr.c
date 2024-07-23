/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:13:56 by rohta             #+#    #+#             */
/*   Updated: 2024/05/25 19:40:20 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		str_sublen;
	size_t		str_len;

	if (s == NULL)
		return (NULL);
	str_len = ft_strlen((void *)(s));
	if (start >= str_len || str_len == 0)
		return (ft_strdup(""));
	if (ft_strlen((void *)(start + s)) < len)
		str_sublen = (ft_strlen((void *)(start + s)));
	else
		str_sublen = len;
	str = (char *)malloc((str_sublen + 1) * (sizeof(char)));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s + start, str_sublen + 1);
	return (str);
}
