/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:30:33 by lsalmi            #+#    #+#             */
/*   Updated: 2021/11/11 16:36:03 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*ptr;
	unsigned long	i;
	void			*result;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (ptr == NULL)
		return (NULL);
	result = ptr;
	while (i < size)
	{
		ptr[i] = '\0';
		i++;
	}
	if (i == size)
		ptr[i] = '\0';
	return (result);
}
