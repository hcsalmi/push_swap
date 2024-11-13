/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:12:40 by lsalmi            #+#    #+#             */
/*   Updated: 2022/08/22 17:12:42 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	percent_char_with_zero_flag(t_options *options, char **content,
		char **new_content, char **temp)
{
	size_t	len;

	len = options->width - options->str_len;
	if (options->dash == 1)
	{
		(*temp) = ft_create_pad_str(len, ' ');
		if (*temp == NULL)
			error_handling(-2);
		(*new_content) = ft_strjoin(*content, *temp);
	}
	else
	{
		(*temp) = ft_create_pad_str(len, '0');
		if (*temp == NULL)
			error_handling(-2);
		(*new_content) = ft_strjoin(*temp, *content);
	}
	if (*new_content == NULL)
		error_handling(-2);
	free(*temp);
	*temp = NULL;
	free(*content);
	*content = NULL;
	*content = *new_content;
}

/*
Function determines the existence of pairs of percentage symbols. If a pair is
completed (no other specifier is found before the second percentage sign),
percentage sign is interpreted to be the specifier (i.e. content is
one percentage symbol).
*/
void	track_percentage_pairs(t_options *options, char **content)
{
	if (options->pair_found == 0)
		options->pair_found = 1;
	else if (options->pair_found == 1)
		options->pair_found = 0;
	if (options->pair_found == 1)
	{
		*content = ft_strndup("%", 1, 0);
		if (*content == NULL)
			error_handling(-2);
	}
	else
		options->edge_case_len = -1;
	options->str_len = 1;
	if (options->precision == 0)
		options->precision = 1;
	if (options->width > 0)
		apply_width_cs(options, content);
}

/*
Counts the number of percentage signs in a row. Determines how many are
to be stored in content.
*/
int	handle_prc(const char *format, unsigned long *offset,
	char **content)
{
	size_t			len;
	unsigned long	start;

	start = *offset;
	while (format[*offset] == '%')
		(*offset)++;
	len = (*offset) - start;
	*content = ft_create_pad_str((len / 2), '%');
	if (*content == NULL)
		error_handling(-2);
	if (len % 2 != 0)
		return (-1);
	return (0);
}
