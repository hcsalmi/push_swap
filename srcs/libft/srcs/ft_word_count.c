/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:25:27 by lsalmi            #+#    #+#             */
/*   Updated: 2022/05/06 16:25:35 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_count(const char *s, char c)
{
	int	i;
	int	count;
	int	in_word_check;

	i = 0;
	count = 0;
	in_word_check = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			in_word_check = 0;
		else if (in_word_check == 0)
		{
			in_word_check = 1;
			count++;
		}
		i++;
	}
	return (count);
}
