/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:26:54 by lsalmi            #+#    #+#             */
/*   Updated: 2021/12/02 13:09:12 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_create_arr(const char *s, char c, char **arr)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < ft_word_count(s, c))
	{
		k = 0;
		while (s[i] == c)
			i++;
		arr[j] = (char *) malloc(sizeof(char) * (ft_word_length(s, c, i) + 1));
		if (arr[j] == NULL)
		{
			ft_free_2d_array((void *)arr, j);
			return (NULL);
		}
		while (s[i] != '\0' && s[i] != c)
			arr[j][k++] = s[i++];
		arr[j][k] = '\0';
		j++;
	}
	arr[j] = 0;
	return (arr);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**arr;

	if (s == NULL || c == '\0')
		return (NULL);
	arr = (char **) malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (arr == NULL)
		return (NULL);
	arr = ft_create_arr(s, c, arr);
	if (arr == NULL)
		return (NULL);
	return (arr);
}
