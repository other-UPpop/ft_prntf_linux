/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:59:11 by rohta             #+#    #+#             */
/*   Updated: 2024/05/14 18:17:44 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s, const char *set)
{
	int		start;
	int		end;
	char	*after_trim;

	start = 0;
	end = ft_strlen((char *)(s));
	if (!s || !set)
		return (NULL);
	while (s[start] != '\0' && ft_strchr(set, s[start]))
		start++;
	while (end > start && ft_strchr(set, s[end - 1]))
		end--;
	if (start >= end)
		return (ft_strdup(""));
	after_trim = ft_substr(s, start, end - start);
	return (after_trim);
}
