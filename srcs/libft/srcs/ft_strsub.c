/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:41:21 by lsalmi            #+#    #+#             */
/*   Updated: 2021/11/19 11:26:18 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned long	i;
	char			*arr;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s) && start < ft_strlen(s))
		len = ft_strlen(s);
	if (start >= ft_strlen(s))
		len = 0;
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
		return (NULL);
	while (i < len)
	{
		arr[i] = s[start];
		i++;
		start++;
	}
	arr[i] = '\0';
	return (arr);
}
