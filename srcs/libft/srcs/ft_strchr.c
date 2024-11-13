/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:07:03 by lsalmi            #+#    #+#             */
/*   Updated: 2021/11/10 13:14:36 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	length;

	i = 0;
	length = ft_strlen(s);
	if ((unsigned char)c == 0 && s[length] == (unsigned char)c)
		return ((char *) &s[length]);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *) &s[i]);
		else
			i++;
	}
	return (NULL);
}
