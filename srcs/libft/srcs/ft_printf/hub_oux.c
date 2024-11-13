/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub_oux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:46:35 by lsalmi            #+#    #+#             */
/*   Updated: 2022/09/21 16:46:43 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
len -2 condition to enable 0x to be added while staying within the allowed width
*/
void	determine_padding_oux(t_options *options, char **temp, size_t len)
{
	if (options->zero == 1 && options->no_precision == 1 && options->dash != 1)
	{
		if (options->hash == 1 && len > 2)
			len = len - 2;
		(*temp) = ft_create_pad_str(len, '0');
		if (*temp == NULL)
			error_handling(-2);
	}
	else
	{
		if (options->zero == 1 && options->hash == 1 && len > 2)
			len = len - 2;
		(*temp) = ft_create_pad_str(len, ' ');
		if (*temp == NULL)
			error_handling(-2);
	}
}

void	apply_width_oux(t_options *options, char **content)
{
	char	*temp;
	size_t	len;
	char	*new_content;

	new_content = NULL;
	temp = NULL;
	if (options->value == 0 && options->precision == 0
		&& options->conversion == 'u')
		*(content)[0] = ' ';
	if (options->width != -1
		&& (unsigned long)options->width > options->str_len)
	{
		len = options->width - options->str_len;
		determine_padding_oux(options, &temp, len);
		dash_flag_joining_rules(options, content, &new_content, temp);
		free_and_null_content(content);
		free(temp);
		*content = new_content;
		options->str_len = ft_strlen(*content);
	}
}

/*
h, hh, l, ll, L
*/
int	apply_prefix_oux(va_list ap, t_options *options)
{
	if (options->hh == 1)
		options->value = (unsigned char)va_arg(ap, int);
	else if (options->h == 1)
		options->value = (unsigned short)va_arg(ap, int);
	else if (options->l == 1)
		options->value = va_arg(ap, unsigned long);
	else if (options->ll == 1)
		options->value = va_arg(ap, unsigned long long);
	else
		return (0);
	return (1);
}

/*
For int types, the precision specifier sets
the minimum number of digits for each number.
Leading zeroes are added to match the required number of digits.
If precision is 0 or omitted, or if the period (.) appears without a number
after it, the precision is set to 1.
The result of converting a zero value with a precision of zero is a null string
(unless the conversion is o, x , or X and the # flag is present).
*/
void	apply_precision_dioux(t_options *options, char **content)
{
	char	*temp;
	char	*new_content;

	new_content = NULL;
	temp = NULL;
	if ((unsigned long)options->precision > options->str_len)
	{
		temp = ft_create_pad_str((options->precision - options->str_len), '0');
		if (temp == NULL)
			error_handling(-2);
		if (options->dash == 0 || (options->precision != 1
				&& options->dash == 1))
			new_content = ft_strjoin(temp, *content);
		else
			new_content = ft_strjoin(*content, temp);
		if (new_content == NULL)
			error_handling(-2);
		if (options->plus == 0 && options->is_neg == 0 && options->space == 1
			&& options->space_added == 0)
			apply_space_di(&new_content, options);
		free(temp);
		free_and_null_content(content);
		options->str_len = ft_strlen(new_content);
		*content = new_content;
	}
}
