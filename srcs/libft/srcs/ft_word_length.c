/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:25:46 by lsalmi            #+#    #+#             */
/*   Updated: 2022/05/06 16:25:53 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_length(const char *s, char c, int i)
{
	int	length;

	length = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		length++;
	}
	return (length);
}
