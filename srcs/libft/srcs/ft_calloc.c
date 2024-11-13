/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:23:12 by lsalmi            #+#    #+#             */
/*   Updated: 2022/10/10 16:23:18 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The difference in malloc and calloc is that malloc does not set the memory to
zero where as calloc sets allocated memory to zero.
count − the number of elements to be allocated.
size − the size of elements.
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = NULL;
	ptr = (void *)malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, (count * size));
	return (ptr);
}
