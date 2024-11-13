/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:57:18 by lsalmi            #+#    #+#             */
/*   Updated: 2022/09/08 16:57:22 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	dash_flag_joining_rules(t_options *options, char **content,
	char **new_content, char *temp)
{
	if (options->dash == 0)
		*new_content = ft_strjoin(temp, *content);
	else
		*new_content = ft_strjoin(*content, temp);
	if (*new_content == NULL)
		error_handling(-2);
}

void	x_preci_and_value_zero(t_options *options, char **content)
{
	free_and_null_content(content);
	*content = ft_create_pad_str(options->width, ' ');
	if (*content == NULL)
		error_handling(-2);
}

void	need_more_padding_x(t_options *options, char **content)
{
	char	*temp;
	char	*new_content;

	temp = NULL;
	new_content = NULL;
	if (options->precision == 0 && options->value == 0)
	{
		x_preci_and_value_zero(options, content);
		return ;
	}
	else if (options->zero == 1 && options->precision == 1
		&& (options->value != 0 && options->hash == 0))
			temp = ft_create_pad_str(options->width
				- (int)options->str_len, '0');
	else if (options->zero == 1 && options->no_precision == 1)
		temp = ft_create_pad_str(options->width - (int)options->str_len, '0');
	else
		temp = ft_create_pad_str(options->width - (int)options->str_len, ' ');
	if (temp == NULL)
		error_handling(-2);
	dash_flag_joining_rules(options, content, &new_content, temp);
	free(temp);
	free_and_null_content(content);
	*content = new_content;
}

void	add_0x_or_not(t_options *options, char **content)
{
	if (options->hash == 1 && options->value != 0 && options->zero == 0)
		add_0x_to_address(content, options);
	else if (options->hash == 1 && options->value != 0 && options->zero == 1
		&& options->width != -1 && options->precision > 1)
		add_0x_to_address(content, options);
	else if (options->width > 0 && options->precision != 0)
		apply_width_oux(options, content);
	if (options->hash == 1 && options->zero == 1 && options->value != 0
		&& options->added_0x == 0)
		add_0x_to_address(content, options);
}

/*
x and X are hexadecimal (base 16) integers (unsigned).
The letters 'abcdef' are used for x, 'ABCDEF' are used for X.
*/
int	handle_x(char **content, va_list ap, t_options *options)
{
	options->base = 16;
	if (options->conversion == 'X')
		options->uppercase = 1;
	if (apply_prefix_oux(ap, options) == 0)
		options->value = va_arg(ap, unsigned int);
	*content = ft_itoa_base((unsigned long)options->value, options->base,
			options->uppercase);
	if (*content == NULL)
		error_handling(-2);
	options->str_len = ft_strlen(*content);
	if (options->precision > 1)
		apply_precision_dioux(options, content);
	check_zero_edge_case(options, content);
	add_0x_or_not(options, content);
	if ((int)options->str_len < options->width)
	{
		need_more_padding_x(options, content);
		options->str_len = ft_strlen(*content);
	}
	return (0);
}
