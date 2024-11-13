/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:02:58 by lsalmi            #+#    #+#             */
/*   Updated: 2022/07/26 13:03:06 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
f
The arg is rounded and converted to decimal notation in the style [-]ddd.ddd
Precision specifes the number of digits to appear after the decimal-point.
If the precision is missing, it is taken as 6.
If the precision is explicitly zero, no decimal-point character appears.
*/
void	apply_precision_f(t_options *options, char **content, char *int_str,
		char *float_str)
{
	long double	float_num;
	int			ret;
	int			i;

	i = 0;
	float_num = determine_float_num(options);
	if (options->l_caps == 1)
	{
		while (i <= options->preci_f)
		{
			float_num = float_num * 10;
			i++;
		}
	}
	ret = long_double_to_str(float_num, float_str, options);
	if (ret == 1)
		round_up_int_part(content, options);
	if (options->preci_f == 0 && options->space_added == 0)
		rounding_int_precision_zero(content, options, ret);
	else if (options->preci_f != 0)
		join_int_and_decimal_part(options, content, int_str, float_str);
	else if (options->space_added == 0)
		*content = int_str;
}

/*
Prefixes that apply: l and L (%lf and %f are treated the same)
*/
int	apply_prefix_f(va_list ap, t_options *options)
{
	int	ret;

	ret = 0;
	if (options->hh == 1)
		return (-6);
	else if (options->h == 1)
		return (-6);
	else if (options->ll == 1)
		return (-6);
	else if (options->l_caps == 1)
		options->float_value = va_arg(ap, long double);
	else
		options->float_value = va_arg(ap, double);
	ret = check_inf_nan(options);
	if ((ret == 0) && (options->float_value < 0 || (options->float_value == 0.0
				&& (1 / options->float_value) != (1 / 0.0))))
	{
		options->is_neg = 1;
		options->float_value = options->float_value * (-1);
	}
	return (ret);
}

int	prefix_hub_f(char **content, va_list ap, t_options *options)
{
	int	ret;

	ret = apply_prefix_f(ap, options);
	if (ret == -6)
		return (-6);
	if (ret == 1 || ret == 2)
		value_is_inf(content, options, ret);
	else if (ret == 3)
		value_is_nan(content, options);
	else
	{
		options->value = options->float_value;
		*content = ft_itoa_base((unsigned long)options->float_value,
				options->base,
				options->uppercase);
		if (*content == NULL)
			error_handling(-2);
		options->value = ft_atoi(*content);
	}
	return (0);
}

/*
Preci_original value is -1, when precision is larger than 18. Decimals up to
18 are filled regularly, rest is filled with zeros.
*/
void	handle_precision_and_dot(char **content, t_options *options)
{
	char	*int_str;
	char	float_str[101];
	char	*new_content;
	char	*temp;

	initialize_pointers_f(&int_str, &new_content, &temp);
	ft_bzero(float_str, 101);
	if (options->inf_nan == 0)
		apply_precision_f(options, content, int_str, float_str);
	if (options->preci_f == 0 && options->hash == 1 && options->inf_nan == 0)
		apply_dot(content);
	if (options->preci_original != -1)
	{
		temp = ft_create_pad_str((options->preci_original
					- ft_strlen(float_str)), '0');
		if (temp == NULL)
			error_handling(-2);
		new_content = ft_strjoin(*content, temp);
		if (new_content == NULL)
			error_handling(-2);
		free(temp);
		free_and_null_content(content);
		*content = new_content;
		options->str_len = ft_strlen(*content);
	}
}

/*
Floating point number. If the # flag appears, a decimal point will be printed
even if the precision is 0.
*/
int	handle_f(char **content, va_list ap, t_options *options)
{
	int	ret;

	if (check_preci_limits_f(options) == -4)
		return (-4);
	ret = prefix_hub_f(content, ap, options);
	if (ret == -2 || ret == -6)
		return (ret);
	apply_space_conditions_f(content, options);
	handle_precision_and_dot(content, options);
	if ((options->is_neg == 1 || options->plus == 1) && options->zero == 0)
	{
		*content = apply_sign(options, content);
		if (*content == NULL)
			error_handling(-2);
	}
	options->str_len = ft_strlen(*content);
	if (options->width > 0)
		apply_width_di(options, content);
	apply_sign_conditions_f(content, options);
	if (options->space == 1 && options->plus == 0 && options->is_neg == 0
		&& options->space_added == 0 && options->zero_padded == 0
		&& options->preci_f != 0 && options->nan == 0)
		apply_space_di(content, options);
	options->str_len = ft_strlen(*content);
	return (0);
}
