/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:41:43 by lsalmi            #+#    #+#             */
/*   Updated: 2021/11/24 17:35:25 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*arr;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) == 0)
		return (NULL);
	arr = ft_strdup(s);
	if (arr == NULL)
		return (NULL);
	while (arr[i] != '\0')
	{
		arr[i] = f(arr[i]);
		i++;
	}
	return (arr);
}
