/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:00:25 by lsalmi            #+#    #+#             */
/*   Updated: 2022/06/20 13:00:28 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
Zero flag handled here.
Variable len indicates the length of padding.
If zero flag present with no precision and no left alignment, zeros are added
instead of spaces.
Exception case for when both zero and spacee flags occur. Condition ensures that
space is added to the front and not the middle.
*/
void	apply_width_di(t_options *options, char **content)
{
	char	*temp;
	size_t	len;
	char	*new_content;

	new_content = NULL;
	temp = NULL;
	if ((unsigned long)options->width > options->str_len)
	{
		len = options->width - options->str_len;
		determine_padding_di_f(options, &temp, len, content);
		if (options->dash == 0)
			new_content = ft_strjoin(temp, *content);
		else
			new_content = ft_strjoin(*content, temp);
		if (new_content == NULL)
			error_handling (-2);
		if (options->zero == 1 && options->precision == 1)
			switch_zero_to_sign(&new_content, options);
		switch_zero_to_space(&new_content, options);
		options->str_len = ft_strlen(*content);
		free(*content);
		*content = NULL;
		free(temp);
		*content = new_content;
	}
}

/*
h, hh, l, ll, L
Sign switched to positive before sending it to ft_itoa_base.
Flag to indicate negative value applied.
*/
void	apply_prefix_di(va_list ap, t_options *options)
{
	if (options->hh == 1)
		options->value = (char)va_arg(ap, int);
	else if (options->h == 1)
		options->value = (short)va_arg(ap, int);
	else if (options->l == 1)
		options->value = va_arg(ap, long);
	else if (options->ll == 1)
		options->value = va_arg(ap, long long);
	else
		options->value = va_arg(ap, int);
	if (options->value < 0)
	{
		options->is_neg = 1;
		options->value = options->value * (-1);
	}
}

void	regular_case_add_sign(t_options *options, char **content)
{
	char	*new_content;

	new_content = NULL;
	new_content = apply_sign(options, content);
	if (new_content == NULL)
		error_handling(-2);
	*content = new_content;
	options->sign_added = 1;
}

/*
When edge_case_len is -1, no node will be created.
Condition: if (options->zero == 1 && options->precision == 1)
ensures that sign is not applied in the wrong spot (in the middle).
*/
int	handle_di(char **content, va_list ap, t_options *options)
{
	apply_prefix_di(ap, options);
	*content = ft_itoa_base((unsigned long)options->value, options->base,
			options->uppercase);
	if (*content == NULL)
		error_handling(-2);
	apply_space_conditions_di(content, options);
	if (options->precision > 1)
		apply_precision_dioux(options, content);
	check_zero_edge_case(options, content);
	if (options->zero == 1 && options->precision == 1)
		apply_sign_conditions_di(content, options);
	else
		regular_case_add_sign(options, content);
	if (options->width > 0)
		apply_width_di(options, content);
	edge_case_add_space(options, content);
	options->str_len = ft_strlen(*content);
	return (0);
}
