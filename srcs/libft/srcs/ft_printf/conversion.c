/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:05:27 by lsalmi            #+#    #+#             */
/*   Updated: 2022/09/12 18:05:30 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
Conversion: cspdiouxXf (and %)
*/
int	invalid_conversion(t_options *options)
{
	free(options);
	return (-5);
}

int	save_conversion_type(const char *format, unsigned long *offset,
	t_options *options)
{
	if (format[(*offset) + 1] == 's')
		options->conversion = 's';
	else if (format[(*offset) + 1] == 'c')
		options->conversion = 'c';
	else if (format[(*offset) + 1] == 'p')
		options->conversion = 'p';
	else if (format[(*offset) + 1] == 'd')
		options->conversion = 'd';
	else if (format[(*offset) + 1] == 'i')
		options->conversion = 'i';
	else if (format[(*offset) + 1] == 'o')
		options->conversion = 'o';
	else if (format[(*offset) + 1] == 'u')
		options->conversion = 'u';
	else if (format[(*offset) + 1] == 'x')
		options->conversion = 'x';
	else if (format[(*offset) + 1] == 'X')
		options->conversion = 'X';
	else if (format[(*offset) + 1] == '%')
		options->conversion = '%';
	else if (format[(*offset) + 1] == 'f')
		options->conversion = 'f';
	else
		return (invalid_conversion(options));
	return (0);
}

int	conversion_is_float(unsigned long *offset, t_options *options,
	char **content, va_list ap)
{
	int	ret;

	ret = handle_f(content, ap, options);
	if (ret == -2 || ret == -4 || ret == -6)
	{
		free(options);
		if (ret == -2)
			error_handling(-2);
		else
			return (ret);
	}
	else
	{
		free(options);
		(*offset)++;
		return (options->edge_case_len);
	}
	return (0);
}

int	check_conversion(unsigned long *offset, char **content, va_list ap,
	t_options *options)
{
	if (options->conversion == 's')
		handle_s(content, ap, options);
	else if (options->conversion == 'c')
		handle_c(content, ap, options);
	else if (options->conversion == 'p')
		handle_p(content, ap, options);
	else if (options->conversion == 'd' || options->conversion == 'i')
		handle_di(content, ap, options);
	else if (options->conversion == 'o')
		handle_o(content, ap, options);
	else if (options->conversion == 'u')
		handle_u(content, ap, options);
	else if (options->conversion == 'x' || options->conversion == 'X')
		handle_x(content, ap, options);
	else if (options->conversion == '%')
		track_percentage_pairs(options, content);
	else if (options->conversion == 'f')
		return (conversion_is_float(offset, options, content, ap));
	free(options);
	(*offset)++;
	return (options->edge_case_len);
}
