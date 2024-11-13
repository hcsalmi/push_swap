/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:49:50 by lsalmi            #+#    #+#             */
/*   Updated: 2021/11/24 13:21:49 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*arr;
	int				length;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * (length + 1));
	if (arr == NULL)
		return (NULL);
	ft_strcpy(arr, s1);
	ft_strcat(arr, s2);
	return (arr);
}
