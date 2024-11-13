/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:27:38 by lsalmi            #+#    #+#             */
/*   Updated: 2022/08/05 13:27:40 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
Leading zero is switched to sign if it's required (specified width maintained).
*/
void	switch_zero_to_sign(char **new_content, t_options *options)
{
	if (options->is_neg == 1 && options->sign_added == 0)
	{
		(*new_content)[0] = '-';
		options->sign_added = 1;
	}
	if (options->is_neg != 1 && options->plus == 1 && options->sign_added == 0)
	{
		(*new_content)[0] = '+';
		options->sign_added = 1;
	}
}

char	*create_sign_string(t_options *options)
{
	char	*str;

	str = NULL;
	str = (char *)malloc(sizeof(char) * 2);
	if (str == NULL)
		return (NULL);
	if (options->is_neg == 1)
		str[0] = '-';
	else
		str[0] = '+';
	str[1] = '\0';
	return (str);
}

int	apply_sign_conditions(t_options *options, char **content,
	char **new_content, char **temp)
{
	if (options->value == 0 && options->plus == 1 && options->conversion != 'f'
		&& options->precision == 0)
	{
		*new_content = ft_create_pad_str(1, '+');
		if (*new_content == NULL)
			error_handling(-2);
		options->edge_case_len = 0;
	}
	else if ((options->is_neg == 1 || options->plus == 1)
		&& options->inf_nan == 0)
		*new_content = ft_strjoin(*temp, *content);
	else
	{
		free(*temp);
		*temp = NULL;
		options->str_len = ft_strlen(*content);
		return (1);
	}
	if (*new_content == NULL)
		error_handling(-2);
	options->sign_added = 1;
	return (0);
}

char	*apply_sign(t_options *options, char **content)
{
	char	*temp;
	char	*new_content;
	int		ret;

	new_content = NULL;
	temp = NULL;
	temp = create_sign_string(options);
	if (temp == NULL)
		error_handling(-2);
	ret = apply_sign_conditions(options, content, &new_content, &temp);
	if (ret == 1)
		return (*content);
	free(temp);
	if ((*content) != NULL)
	{
		free(*content);
		*content = NULL;
	}
	options->str_len = ft_strlen(new_content);
	return (new_content);
}

void	apply_dot(char **content)
{
	char	*temp;

	temp = NULL;
	temp = *content;
	*content = ft_strjoin(temp, ".");
	if (*content == NULL)
		error_handling(-2);
	free(temp);
}
