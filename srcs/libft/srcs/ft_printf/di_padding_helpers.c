/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_padding_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:40:40 by lsalmi            #+#    #+#             */
/*   Updated: 2022/09/21 18:40:42 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	di_padding_is_space(t_options *options, char **temp, size_t len)
{
	if ((options->conversion == 'd' || options->conversion == 'i')
		&& options->space == 1 && options->dash == 1
		&& options->precision == 0 && options->value != 0
		&& options->is_neg == 0 && options->plus == 0)
	{
		len = len - 1;
	}
	(*temp) = ft_create_pad_str(len, ' ');
	if (*temp == NULL)
		error_handling(-2);
	options->space_padded = 1;
}

size_t	ft_number_len(unsigned long n, int base)
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

void	zero_flag_ignored_di(char **content, char **temp, size_t len,
		t_options *options)
{
	options->zero = 0;
	options->space = 0;
	if (options->is_neg == 1 || options->plus == 1)
	{
		regular_case_add_sign(options, content);
		len = len - 1;
		options->str_len = ft_strlen(*content);
	}
	(*temp) = ft_create_pad_str(len, ' ');
	if (*temp == NULL)
		error_handling(-2);
}

void	apply_padding_conditions_di(char **content, char **temp, size_t len,
		t_options *options)
{
	if ((int)ft_number_len(ft_atoi(*content), 10) > options->precision
		&& options->no_precision == 0 && options->zero == 1
		&& (options->conversion == 'd' || options->conversion == 'i'))
		zero_flag_ignored_di(content, temp, len, options);
	else if ((options->conversion == 'd' || options->conversion == 'i')
		&& options->value == 0 && options->no_precision == 0)
		(*temp) = ft_create_pad_str(len, ' ');
	else if ((options->conversion == 'd' || options->conversion == 'i')
		&& options->value != 0 && options->space == 1
		&& options->no_precision == 0)
	{
		*content = apply_sign(options, content);
		if (*content == NULL)
			error_handling(-2);
		if (options->is_neg == 1 || options->plus == 1)
			len = len - 1;
		(*temp) = ft_create_pad_str(len, ' ');
	}
	else
	{
		options->zero_padded = 1;
		(*temp) = ft_create_pad_str(len, '0');
	}
	if (*temp == NULL)
		error_handling(-2);
}

/*
Signed decimal integer (d and i), assumes base 10
The precision gives the minimum number of digits that must appear;
if the value requires fewer digits, it is padded on the left with zeros.
*/
void	determine_padding_di_f(t_options *options, char **temp, size_t len,
		char **content)
{
	if (options->conversion == '%' && options->zero == 1)
	{
		(*temp) = ft_create_pad_str(len, '0');
		if (*temp == NULL)
			error_handling(-2);
	}
	else if (options->zero == 1 && options->precision == 1 && options->dash == 0
		&& options->inf_nan == 0)
		apply_padding_conditions_di(content, temp, len, options);
	else if (options->conversion == 'f' && options->dash == 0
		&& options->zero == 1 && options->inf_nan == 0)
	{
		(*temp) = ft_create_pad_str(len, '0');
		if (*temp == NULL)
			error_handling(-2);
		options->zero_padded = 1;
	}
	else
		di_padding_is_space(options, temp, len);
}
