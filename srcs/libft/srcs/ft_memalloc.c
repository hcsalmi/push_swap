/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:50:22 by lsalmi            #+#    #+#             */
/*   Updated: 2021/11/11 16:21:23 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr;
	unsigned long	i;
	void			*result;

	i = 0;
	ptr = (unsigned char *)malloc(sizeof(unsigned char) * (size));
	if (ptr == NULL)
	{
		return (NULL);
	}
	result = ptr;
	while (i < size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (result);
}
