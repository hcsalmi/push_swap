/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:49:15 by lsalmi            #+#    #+#             */
/*   Updated: 2022/06/23 12:49:17 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	apply_width_cs(t_options *options, char **content)
{
	char	*temp;
	size_t	len;
	char	*new_content;

	new_content = NULL;
	temp = NULL;
	if (options->conversion == '%' && options->zero == 1
		&& (unsigned long)options->width > options->str_len)
		percent_char_with_zero_flag(options, content, &new_content, &temp);
	else if (options->precision == 0 && options->width > 0)
		string_not_printed(options, content);
	else if ((unsigned long)options->width > options->str_len)
	{
		len = options->width - options->str_len;
		temp = ft_create_pad_str(len, ' ');
		if (temp == NULL)
			error_handling(-2);
		if (options->edge_case_len != 0)
			null_char_exception(options, &new_content, &temp, len);
		else
			join_strings_cs(options, content, &temp, &new_content);
		free(temp);
		free_and_null_content(content);
		*content = new_content;
	}
}

void	precision_edge_cases_cs(t_options *options)
{
	if (options->precision == 0 && options->width == -1)
		options->edge_case_len = -1;
	if (options->no_precision == 1)
		options->precision = options->str_len;
}

/*
When applying to strings, the precision specifier sets the maximum field length.
For example, %5.7s displays a string at least five and not exceeding seven
characters. No more than the number specified are written.
If the string is longer than the maximum field width, end will be truncated.
When precision is not defined, it is taken as infinite.
*/
void	apply_precision_cs(t_options *options, char **content)
{
	char	*new_content;

	new_content = NULL;
	precision_edge_cases_cs(options);
	if (options->precision == 1
		&& (unsigned long)options->precision < options->str_len)
	{
		new_content = ft_strndup(*content, 1, 0);
		if (new_content == NULL)
			error_handling(-2);
		free_and_null_content(content);
		options->str_len = 1;
		*content = new_content;
	}
	if (options->precision > 1
		&& (unsigned long)options->precision < options->str_len)
	{
		new_content = ft_strndup(*content,
				(unsigned long)options->precision, 0);
		if (new_content == NULL)
			error_handling(-2);
		free_and_null_content(content);
		options->str_len = ft_strlen(new_content);
		*content = new_content;
	}
}

int	handle_c(char **content, va_list ap, t_options *options)
{
	char	c;

	c = (char)va_arg(ap, int);
	options->str_len = 1;
	*content = ft_strndup(&c, 1, 0);
	if (*content == NULL)
		error_handling(-2);
	if (c == '\0')
		options->edge_case_len = 1;
	if (options->width > 0)
		apply_width_cs(options, content);
	return (options->edge_case_len);
}

int	handle_s(char **content, va_list ap, t_options *options)
{
	char	*str;

	str = NULL;
	options->edge_case_len = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
	{
		*content = ft_strdup("(null)");
		if (*content == NULL)
			error_handling(-2);
		options->str_len = 6;
	}
	else
	{
		*content = ft_strdup(str);
		if (*content == NULL)
			error_handling(-2);
		options->str_len = ft_strlen(str);
	}
	apply_precision_cs(options, content);
	if (options->width > 0)
		apply_width_cs(options, content);
	return (options->edge_case_len);
}
