/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_char_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:34:20 by lsalmi            #+#    #+#             */
/*   Updated: 2022/05/13 12:44:39 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_char_array(char **array)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (array[len] != NULL)
		len++;
	while (i < len)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
