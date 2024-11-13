/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:32:48 by lsalmi            #+#    #+#             */
/*   Updated: 2021/11/24 19:10:14 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	increase_ijm(int *i, int *j, unsigned long *m)
{
	(*i)++;
	(*j)++;
	(*m)++;
}

static void	increase_ikm(int *i, int *k, unsigned long *m)
{
	(*k)++;
	*i = *k;
	*m = *k;
}

static void	initialize_variables(int *i, int *j, int *k, unsigned long *m)
{
	*i = 0;
	*j = 0;
	*k = 0;
	*m = 0;
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int				i;
	int				j;
	int				k;
	unsigned long	m;

	initialize_variables(&i, &j, &k, &m);
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (haystack[i] != '\0' && m < len)
	{
		while (needle[j] == haystack[i] && m < len)
		{
			increase_ijm(&i, &j, &m);
			if (needle[j] == '\0')
				return ((char *)&haystack[i - j]);
		}
		if (haystack[i] != needle[0])
			increase_ikm(&i, &k, &m);
		j = 0;
	}
	return (NULL);
}
