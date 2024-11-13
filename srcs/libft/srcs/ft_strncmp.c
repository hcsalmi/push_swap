/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:19:47 by lsalmi            #+#    #+#             */
/*   Updated: 2021/11/19 15:26:04 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned long	i;
	int				result;

	i = 0;
	result = 0;
	if (n == 0)
		return (result);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
		i++;
	if (s1[i] != s2[i])
	{
		result = ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (result);
}
