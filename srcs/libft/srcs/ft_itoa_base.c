/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:27:02 by lsalmi            #+#    #+#             */
/*   Updated: 2022/06/15 14:27:06 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_putnbr_mod(unsigned long n, char *str, unsigned long base,
	int uppercase)
{
	if (n > (base - 1))
	{
		ft_putnbr_mod(n / base, str, base, uppercase);
		ft_putnbr_mod(n % base, str, base, uppercase);
	}
	else
	{
		while (*str)
			str++;
		if (n < 10)
			*str = n + '0';
		else
		{
			if (uppercase == 1)
				*str = (n - 10) + 'A';
			else
				*str = (n - 10) + 'a';
		}
	}
	return (str);
}

static size_t	ft_number_len(unsigned long n, int base)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n = n / base;
		count++;
	}
	return (count);
}

char	*ft_itoa_base(unsigned long n, int base, int uppercase)
{
	int		len;
	char	*str;

	if (base < 2 || base > 16)
		return (NULL);
	len = ft_number_len(n, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_bzero(str, (sizeof(char) * (len + 1)));
	str = ft_putnbr_mod(n, str, (unsigned long)base, uppercase);
	return (str);
}
