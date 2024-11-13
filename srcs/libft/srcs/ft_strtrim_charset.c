/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_charset.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:28:14 by lsalmi            #+#    #+#             */
/*   Updated: 2022/12/08 14:28:19 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trim_back(char const *s, char const *set, int *i, int length)
{
	int	j;

	j = 0;
	while (((*i) >= 0 && length > 0) && set[j] != '\0')
	{
		while (set[j] != '\0')
		{
			if (s[(*i)] == set[j])
			{
				(*i)--;
				length--;
				j = 0;
			}
			else if (s[(*i)] != set[j])
				j++;
		}
	}
	return (length);
}

static int	trim_front(char const *s, char const *set, int *i)
{
	int	length;
	int	j;

	j = 0;
	length = 0;
	while (s[(*i)] != '\0' && set[j] != '\0')
	{
		if (s[(*i)] == set[j])
		{
			(*i)++;
			j = 0;
		}
		else if (s[(*i)] != set[j])
			j++;
	}
	while (s[(*i)] != '\0')
	{
		(*i)++;
		length++;
	}
	return (length);
}

static int	ft_strlen_trim_charset(char const *s, char const *set)
{
	int	i;
	int	length;

	i = 0;
	length = trim_front(s, set, &i);
	if (length == 0)
		return (0);
	i--;
	length = trim_back(s, set, &i, length);
	return (length);
}

static void	find_start_index(char const *s, char const *set, int *i)
{
	int	j;

	j = 0;
	while (s[(*i)] != '\0' && set[j] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s[(*i)] == set[j])
			{
				(*i)++;
				break ;
			}
			else if (s[(*i)] != set[j])
				j++;
		}
	}
}

char	*ft_strtrim_charset(char const *s1, char const *set)
{
	int				i;
	char			*arr;
	unsigned long	length;
	unsigned long	j;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return (NULL);
	length = ft_strlen_trim_charset(s1, set);
	arr = (char *)malloc(sizeof(char) * (length + 1));
	if (arr == NULL)
		return (NULL);
	find_start_index(s1, set, &i);
	while (j < length)
	{
		arr[j] = s1[i];
		i++;
		j++;
	}
	arr[j] = '\0';
	return (arr);
}
