/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:07:28 by rohta             #+#    #+#             */
/*   Updated: 2024/05/20 14:23:49 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char ((*f)(unsigned int, char)))
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc((sizeof (char) * (ft_strlen(s) + 1)));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f((unsigned char)i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
