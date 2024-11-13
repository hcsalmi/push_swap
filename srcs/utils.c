/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:45:22 by lsalmi            #+#    #+#             */
/*   Updated: 2023/01/18 16:45:28 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	trim_front(char	*str, long *sign, int *i)
{
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n'
		|| str[*i] == '\v' || str[*i] == '\f' || str[*i] == '\r')
		(*i)++;
	if (str[*i] == '-')
		*sign = -1;
	if (str[*i] == '-' || str[*i] == '+')
		(*i)++;
}

long	ft_atol(char *str)
{
	int		i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	trim_front(str, &sign, &i);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		result = (result * 10) + (str[i++] - '0');
	return (sign * result);
}
