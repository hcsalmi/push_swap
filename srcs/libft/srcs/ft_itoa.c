/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:55:24 by lsalmi            #+#    #+#             */
/*   Updated: 2022/11/08 10:25:56 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_mod(int n, char *arr, int *i)
{
	if (n < 0)
		n = -n;
	if (n > 9)
	{
		ft_putnbr_mod(n / 10, arr, i);
		ft_putnbr_mod(n % 10, arr, i);
	}
	else
		arr[(*i)++] = n + '0';
}

static unsigned long	ft_int_len(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		count = 1;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*arr;
	int		temp_n;

	i = 0;
	temp_n = n;
	arr = (char *)malloc(sizeof(char) * (ft_int_len(n) + 1));
	if (arr == NULL)
		return (NULL);
	n = temp_n;
	if (n < 0)
	{
		arr[0] = '-';
		i++;
	}
	if (n == -2147483648)
	{
		arr[i++] = '2';
		n = -147483648;
	}
	ft_putnbr_mod(n, arr, &i);
	arr[i] = '\0';
	return (arr);
}
