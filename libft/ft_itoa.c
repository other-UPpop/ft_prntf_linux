/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:23:03 by rohta             #+#    #+#             */
/*   Updated: 2024/05/22 18:32:08 by rohta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_islen(long int n)
{
	size_t	i;

	i = 1;
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int	num;
	size_t		len;
	char		*s;

	num = n;
	len = ft_islen(num);
	if (n < 0)
	{
		num *= -1;
		len++;
	}
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	while (len--)
	{
		s[len] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
