/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:46:04 by lsalmi            #+#    #+#             */
/*   Updated: 2021/11/24 13:18:10 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_trim(char const *s)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (length);
	while (s[i] != '\0')
	{
		i++;
		length++;
	}
	i--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		length--;
		i--;
	}
	return (length);
}

char	*ft_strtrim(char const *s)
{
	unsigned long	i;
	char			*arr;
	unsigned long	length;
	unsigned long	j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	length = ft_strlen_trim(s);
	arr = (char *)malloc(sizeof(char) * (length + 1));
	if (arr == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (j < length)
	{
		arr[j] = s[i];
		i++;
		j++;
	}
	arr[j] = '\0';
	return (arr);
}
