/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:16:47 by lsalmi            #+#    #+#             */
/*   Updated: 2022/08/05 13:16:50 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strreverse(char *str, int len)
{
	int	front;
	int	back;
	int	temp;

	front = 0;
	back = len - 1;
	while (front < back)
	{
		temp = str[front];
		str[front] = str[back];
		str[back] = temp;
		front++;
		back--;
	}
}
