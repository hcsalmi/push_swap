/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_rounding_helpers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:11:20 by lsalmi            #+#    #+#             */
/*   Updated: 2022/09/21 18:11:22 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
Max precision set to 100.
*/
int	check_preci_limits_f(t_options *options)
{
	if (options->preci_f > 100)
		return (-4);
	else if (options->preci_f > 15 && options->l_caps == 1)
	{
		options->preci_original = options->precision;
		options->precision = 15;
		options->preci_f = options->precision;
	}
	else if (options->preci_f > 18)
	{
		options->preci_original = options->precision;
		options->precision = 18;
		options->preci_f = options->precision;
	}
	return (0);
}

void	precision_to_str(const char *format, unsigned long *offset,
	char *num_string)
{
	int	i;

	i = 0;
	while (1)
	{
		if (format[*offset] == '\0' || i > 3)
			break ;
		else if (ft_isdigit(format[(*offset) + 1]) == 1)
		{
			num_string[i] = format[(*offset) + 1];
			i++;
		}
		else
			break ;
		(*offset)++;
	}
	while (ft_isdigit(format[(*offset) + 1]) == 1)
		(*offset)++;
}

void	rounding_int_precision_zero(char **content, t_options *options, int ret)
{
	free(*content);
	*content = NULL;
	if (ret == 1)
	{
		*content = ft_itoa_base((unsigned long)options->float_value + 1, 10, 0);
		if (*content == NULL)
			error_handling(-2);
	}
	else
	{
		*content = ft_itoa_base((unsigned long)options->float_value, 10, 0);
		if (*content == NULL)
			error_handling(-2);
	}
}

void	round_up_int_part(char **content, t_options *options)
{
	free(*content);
	*content = NULL;
	options->value = options->value + 1;
	*content = ft_itoa_base((unsigned long)options->value, 10, 0);
	if (*content == NULL)
		error_handling(-2);
	options->str_len = ft_strlen(*content);
}

int	lf_rounding_edge_case(long double n, int rounding, t_options *options)
{
	if (rounding == 5 && (options->value == 0
			|| options->value % 2 == 0) && ((n * 100) <= 50
			|| (options->l_caps == 1 && (n * 100) <= 500)))
		return (1);
	else
		return (0);
}
