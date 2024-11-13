/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:11:53 by lsalmi            #+#    #+#             */
/*   Updated: 2022/09/12 18:11:55 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	apply_sign_conditions_f(char **content, t_options *options)
{
	if ((options->is_neg == 1 || options->plus == 1) && options->zero == 1)
	{
		if (options->width > 0 && options->zero == 1
			&& options->zero_padded == 1)
			switch_zero_to_sign(content, options);
		else if (*content[0] != '-' && *content[0] != '+')
		{
			*content = apply_sign(options, content);
			if (*content == NULL)
				error_handling(-2);
		}
	}
}

void	apply_space_conditions_f(char **content, t_options *options)
{
	if (options->space == 1 && options->plus == 0 && options->is_neg == 0
		&& options->preci_f != 0 && options->inf_nan == 0)
	{
		if (options->zero == 1 && options->space == 1)
			options->space_added = 0;
		else
			apply_space_di(content, options);
	}
	else if (options->space == 1 && options->plus == 0 && options->is_neg == 0
		&& options->dash == 1)
		apply_space_di(content, options);
	options->str_len = ft_strlen(*content);
}

void	initialize_pointers_f(char	**int_str, char	**new_content, char	**temp)
{
	*int_str = NULL;
	*new_content = NULL;
	*temp = NULL;
}

void	join_int_and_decimal_part(t_options *options, char **content,
	char *int_str, char *float_str)
{
	char	dot_str[2];

	ft_bzero(dot_str, 2);
	dot_str[0] = '.';
	dot_str[1] = '\0';
	int_str = ft_strjoin(*content, dot_str);
	if (int_str == NULL)
		error_handling(-2);
	free_and_null_content(content);
	options->str_len = ft_strlen(int_str);
	*content = ft_strjoin(int_str, float_str);
	if (*content == NULL)
		error_handling(-2);
	options->str_len = ft_strlen(*content);
	free(int_str);
}

void	find_end_of_dec_array(int *len, char *dec_array)
{
	while (dec_array[(*len)] != '\0')
		(*len)++;
	(*len)--;
}
