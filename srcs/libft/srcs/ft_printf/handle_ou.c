/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ou.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:56:27 by lsalmi            #+#    #+#             */
/*   Updated: 2022/09/08 16:56:39 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	need_more_padding_o(t_options *options, char **content)
{
	char	*temp;
	char	*new_content;

	temp = NULL;
	new_content = NULL;
	if (options->precision == 0 && options->value == 0)
	{
		free_and_null_content(content);
		*content = ft_create_pad_str(options->width, ' ');
		if (*content == NULL)
			error_handling(-2);
		return ;
	}
	else if (options->zero == 1 && options->precision < 2)
		temp = ft_create_pad_str(options->width - (int)options->str_len, '0');
	else
		temp = ft_create_pad_str(options->width - (int)options->str_len, ' ');
	if (temp == NULL)
		error_handling(-2);
	dash_flag_joining_rules(options, content, &new_content, temp);
	free(temp);
	free_and_null_content(content);
	*content = new_content;
	options->str_len = ft_strlen(*content);
}

void	apply_hash_o(t_options *options, char **content)
{
	char	*temp;

	temp = NULL;
	temp = *content;
	*content = ft_strjoin("0", temp);
	if (*content == NULL)
		error_handling(-2);
	free (temp);
	options->str_len = ft_strlen(*content);
}

/*
Hash for o conversions: the precision of the number is increased to force
the first character of the output string to a zero.
*/
void	apply_hash_or_not(t_options *options, char **content)
{
	char	*temp;
	char	*new_content;

	new_content = NULL;
	temp = NULL;
	if (options->hash == 1 && options->is_neg == 0 && options->value != 0)
		apply_hash_o(options, content);
	else if (options->hash == 1 && options->value == 0 && options->zero == 0)
	{
		if ((unsigned long)options->precision > options->str_len)
		{
			temp = ft_create_pad_str(options->precision
					- (int)options->str_len, '0');
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
		apply_width_oux(options, content);
	}
}

/*
An unsigned octal (base 8) integer.
if (options->width > 0 && options->precision != 0 && options->value != 0)
condition ensures that padding is not being created a second time.
*/
int	handle_o(char **content, va_list ap, t_options *options)
{
	options->base = 8;
	if (apply_prefix_oux(ap, options) == 0)
		options->value = va_arg(ap, unsigned int);
	*content = ft_itoa_base((unsigned long)options->value, options->base,
			options->uppercase);
	if (*content == NULL)
		error_handling(-2);
	options->str_len = ft_strlen(*content);
	apply_hash_or_not(options, content);
	if (options->precision > 1)
		apply_precision_dioux(options, content);
	if (options->value == 0 && options->precision == 0 && options->hash != 1)
		check_zero_edge_case(options, content);
	if (options->width > 0 && options->value != 0)
		apply_width_oux(options, content);
	if ((int)options->str_len < options->width)
		need_more_padding_o(options, content);
	return (0);
}

/*
An unsigned decimal.
*/
int	handle_u(char **content, va_list ap, t_options *options)
{
	if (apply_prefix_oux(ap, options) == 0)
		options->value = va_arg(ap, unsigned int);
	*content = ft_itoa_base((unsigned long)options->value, options->base,
			options->uppercase);
	if (*content == NULL)
		error_handling(-2);
	options->str_len = ft_strlen(*content);
	if (options->precision > 1)
		apply_precision_dioux(options, content);
	if (options->width > 0)
		apply_width_oux(options, content);
	if (options->value == 0 && options->precision == 0 && options->width < 1)
		*(content)[0] = '\0';
	return (0);
}
