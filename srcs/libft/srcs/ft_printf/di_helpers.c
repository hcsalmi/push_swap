/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:13:33 by lsalmi            #+#    #+#             */
/*   Updated: 2022/09/09 15:13:35 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	apply_sign_conditions_di(char **content, t_options *options)
{
	char	*new_content;

	new_content = NULL;
	if (((options->is_neg == 1 || options->plus == 1)
			&& (options->width < (int)options->str_len))
		|| (options->dash == 1 && (options->is_neg == 1 || options->plus == 1)))
	{
		new_content = apply_sign(options, content);
		if (new_content == NULL)
			error_handling(-2);
		*content = new_content;
	}
	else if ((options->is_neg == 1 || options->plus == 1)
		&& options->zero == 1 && options->width == (int)options->str_len)
	{
		new_content = apply_sign(options, content);
		if (new_content == NULL)
			error_handling(-2);
		*content = new_content;
	}
}

void	apply_space_conditions_di(char **content, t_options *options)
{
	if (options->space == 1 && options->plus == 0 && options->is_neg == 0
		&& options->precision == 1 && options->zero == 0)
		apply_space_di(content, options);
	else if (options->space == 1 && options->plus == 0 && options->is_neg == 0
		&& options->precision > 1 && options->dash == 1
		&& options->precision <= (int)ft_strlen(*content))
		apply_space_di(content, options);
	options->str_len = ft_strlen(*content);
}

void	switch_zero_to_space(char **new_content, t_options *options)
{
	if (options->zero == 1 && options->space == 1 && options->is_neg == 0
		&& options->plus == 0)
	{
		(*new_content)[0] = ' ';
		options->space_added = 1;
	}
}

void	apply_space_di(char **content, t_options *options)
{
	char	*temp;

	temp = NULL;
	temp = *content;
	*content = ft_strjoin(" ", temp);
	if (*content == NULL)
		error_handling (-2);
	free(temp);
	options->space_added = 1;
}

void	edge_case_add_space(t_options *options, char **content)
{
	if (options->space == 1 && options->space_added == 0 && options->plus == 0
		&& options->is_neg == 0 && (options->space_padded == 0
			|| options->dash == 1))
	{
		if (options->value == 0 && options->precision == 0)
			return ;
		apply_space_di(content, options);
	}
}
