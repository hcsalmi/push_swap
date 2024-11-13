/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_edges_handling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:28:32 by lsalmi            #+#    #+#             */
/*   Updated: 2022/08/05 14:28:39 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
(-1 ret: do not create a node) ->handled elsewhere (not an error)
-2 ret: malloc error
-3 ret: width too large
-4 ret: precision too large
-5 ret: invalid conversion type
-6 ret: invalid prefix
*/
void	error_handling(int code)
{
	if (code == -2)
	{
		write(2, "malloc error\n", 13);
		exit (-2);
	}
	if (code == -3)
		write(2, "error: width value too large\n", 29);
	if (code == -4)
		write(2, "error: precision value too large\n", 33);
	if (code == -5)
		write(2, "error: invalid conversion specifier\n", 36);
	if (code == -6)
		write(2, "error: invalid prefix\n", 22);
}

/*
When applying width to strings:
If precision is zero and width is larger than zero, only spaces are printed.
*/
void	string_not_printed(t_options *options, char **content)
{
	size_t	len;

	free(*content);
	*content = NULL;
	len = options->width;
	*content = ft_create_pad_str(len, ' ');
	if (*content == NULL)
		error_handling(-2);
}

void	null_char_exception(t_options *options, char **new_content,
		char **temp, size_t len)
{
	options->str_len = len;
	(*new_content) = strjoin_null_char(*temp, options, (len + 1));
	if (*new_content == NULL)
		error_handling(-2);
	options->edge_case_len = len + 1;
}

void	check_zero_edge_case(t_options *options, char **content)
{
	if (options->value == 0 && options->precision == 0 && options->space == 0)
	{
		if (options->width < 1)
			options->edge_case_len = -1;
		else
		{
			free(*content);
			*content = NULL;
			*content = ft_create_pad_str(options->width, ' ');
			if (*content == NULL)
				error_handling(-2);
		}
	}
	else if (options->value == 0 && options->precision == 0
		&& options->space == 1)
	{
		free(*content);
		*content = NULL;
		*content = ft_create_pad_str(1, ' ');
		if (*content == NULL)
			error_handling(-2);
	}
	options->str_len = ft_strlen(*content);
}
