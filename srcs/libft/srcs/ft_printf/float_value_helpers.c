/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_value_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:15:04 by lsalmi            #+#    #+#             */
/*   Updated: 2022/09/12 18:15:06 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long double	determine_float_num(t_options *options)
{
	long double	float_num;

	if (options->float_value > 0)
		float_num = options->float_value - (unsigned long)options->float_value;
	else
		float_num = options->float_value;
	return (float_num);
}

void	value_is_nan(char **content, t_options *options)
{
	*content = ft_strdup("nan");
	if (*content == NULL)
		error_handling(-2);
	options->inf_nan = 1;
	options->nan = 1;
	options->plus = 0;
}

void	value_is_inf(char **content, t_options *options, int ret)
{
	if (ret == 1)
	{
		if (options->plus == 1)
		{
			*content = ft_strdup("+inf");
			if (*content == NULL)
				error_handling(-2);
			options->sign_added = 1;
			options->plus = 0;
		}
		else
			*content = ft_strdup("inf");
		if (*content == NULL)
			error_handling(-2);
	}
	else if (ret == 2)
	{
		*content = ft_strdup("-inf");
		if (*content == NULL)
			error_handling(-2);
		options->is_neg = 1;
		options->plus = 0;
		options->sign_added = 1;
	}
	options->inf_nan = 1;
}

int	check_inf_nan(t_options *options)
{
	if (options->float_value == (1.0 / 0.0))
		return (1);
	else if (options->float_value == (-1.0 / 0.0))
		return (2);
	else if (options->float_value != options->float_value)
		return (3);
	else
		return (0);
}

void	multiply_temp(long double *temp, t_options *options)
{
	int		i;

	i = 0;
	while (i <= options->preci_f)
	{
		*temp = (*temp) * 10;
		i++;
	}
}
