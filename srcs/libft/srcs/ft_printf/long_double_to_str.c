/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_double_to_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:13:21 by lsalmi            #+#    #+#             */
/*   Updated: 2022/07/29 14:13:59 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	apply_rounding_f(char **dec_array, int rounding_value, t_options *options,
	int len)
{
	long double	temp;

	temp = options->float_value * 10000;
	if ((options->preci_f == 1 && (*dec_array)[len] == '2'
		&& options->no_flags == 1 && rounding_value == 5
		&& (((options->float_value - options->value) * 100) <= 50)))
		return (0);
	if (options->preci_f == 2 && (*dec_array)[len] == '2'
		&& options->no_flags == 1 && rounding_value == 5
		&& ((int)temp % 10 == 0))
		return (0);
	else if ((len == 0 && (*dec_array)[len] == '2' && ((options->hash == 1
				&& (options->preci_f == 0 || options->preci_f == 1
					|| options->preci_f == 2)) || options->zero == 1))
		&& (options->float_value * 100) <= 50)
		return (0);
	(*dec_array)[len] = (*dec_array)[len] + 1;
	return (0);
}

/*
Function goes through indexes and rounds up based on rounding value. If digit
to be rounded up is 9, change 9 to 0, move on to previous decimal.
If return value is 1, integer part needs to be rounded up.
*/
int	rounding_floats(char *dec_array, int rounding_value, t_options *options,
	int len)
{
	find_end_of_dec_array(&len, dec_array);
	while (len >= 0)
	{
		if (rounding_value >= 0 && rounding_value <= 4)
			return (0);
		else
		{
			if (dec_array[len] >= '0' && dec_array[len] <= '8')
			{
				apply_rounding_f(&dec_array, rounding_value, options, len);
				return (0);
			}
			else if (rounding_value == 5 && options->preci_f == 1
				&& options->value == 0 && options->l_caps == 1
				&& dec_array[0] == '9')
				return (0);
			else
			{
				dec_array[len] = '0';
				len--;
			}
		}
	}
	return (1);
}

int	find_rounding_value(int i, int digits, char *str)
{
	int	temp;
	int	rounding;

	rounding = 0;
	if (i > digits)
	{
		temp = digits;
		while (temp <= i)
		{
			str[temp] = '\0';
			temp++;
		}
		rounding = ft_atoi(&str[digits - 1]);
		str[digits - 1] = '\0';
	}
	else
	{
		rounding = ft_atoi(&str[i - 1]);
		str[i - 1] = '\0';
		str[i] = '\0';
	}
	return (rounding);
}

int	num_to_str(long long nb, char *str, int digits)
{
	int	i;
	int	rounding;

	rounding = 0;
	i = 0;
	while (nb > 0)
	{
		str[i] = (nb % 10) + '0';
		i++;
		nb = nb / 10;
	}
	while (i < digits)
	{
		str[i] = '0';
		i++;
	}
	ft_strreverse(str, i);
	rounding = find_rounding_value(i, digits, str);
	return (rounding);
}

/*
Banker's rounding applied. If precision is zero and the deciding decimal is 5,
the number is rounded to the nearest even number (sometimes up, sometimes down).
*/
int	long_double_to_str(long double n, char *dec_array, t_options *options)
{
	long double	temp;
	int			rounding;
	int			len;

	len = 0;
	temp = n;
	if (n == 0.0 && (1 / n != 1 / 0.0))
		options->is_neg = 1;
	if (options->preci_f == 0)
	{
		temp = temp * 10;
		rounding = num_to_str((long long)temp, dec_array, 1);
		if (rounding < 5 || lf_rounding_edge_case(n, rounding, options) == 1)
			return (0);
	}
	if (options->preci_f != 0)
	{
		multiply_temp(&temp, options);
		if (options->l_caps == 1)
			temp = n;
		rounding = num_to_str((long long)temp, dec_array, options->preci_f + 1);
	}
	return (rounding_floats(dec_array, rounding, options, len));
}
