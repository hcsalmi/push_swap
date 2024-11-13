/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:42:22 by lsalmi            #+#    #+#             */
/*   Updated: 2022/06/16 14:42:26 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_prefix(const char *format, unsigned long *offset, t_options *options)
{
	while (1)
	{
		if (format[*offset] == '\0')
			break ;
		else if (format[*(offset) + 1] == 'h' && format[*(offset) + 2] == 'h')
			options->hh = 1;
		else if (format[*(offset) + 1] == 'h')
			options->h = 1;
		else if (format[*(offset) + 1] == 'l' && format[*(offset) + 2] == 'l')
			options->ll = 1;
		else if (format[*(offset) + 1] == 'l')
			options->l = 1;
		else if (format[*(offset) + 1] == 'L')
			options->l_caps = 1;
		else
			break ;
		(*offset)++;
	}
	return (0);
}

/*
An optional precision, in the form of a period '.' followed by a digit string.
If the digit string is omitted, the precision is zero.
Precision gives the minimum number of digits to appear for
d, i, o, u, x, and X,
the number of digits to appear after the decimal-point for
a, A, e, E, f, and F,
and maximum number of characters to be printed from a string for s conversions.
For c conversion type, it has no effect.
*/
int	check_precision(const char *format, unsigned long *offset,
	t_options *options)
{
	char	num_string[4];

	(*offset)++;
	if (format[(*offset) + 1] == 0 || ft_isdigit(format[(*offset) + 1]) != 1)
	{
		options->precision = 0;
		options->preci_f = 0;
		return (0);
	}
	ft_bzero(num_string, 4);
	precision_to_str(format, offset, num_string);
	options->precision = ft_atoi(num_string);
	options->preci_f = options->precision;
	return (0);
}

/*
If the converted value has fewer characters than the field width,
it will be padded with spaces on the left (or right, if the left-adjustment flag
has been given) to fill out the field width.
Non-existent or small field width does not cause truncation of a numeric field.
If the result of a conversion is wider than the field width,
the field is expanded to contain the conversion result.
*/
int	check_width(const char *format, unsigned long *offset, t_options *options)
{
	char	num_string[25];
	int		i;

	ft_bzero(num_string, 25);
	i = 0;
	if (ft_isdigit(format[(*offset) + 1]) != 1)
	{
		options->no_width = 1;
		return (-1);
	}
	while (1)
	{
		if (format[*offset] == '\0' || ft_isdigit(format[(*offset) + 1]) != 1)
			break ;
		else if (ft_isdigit(format[(*offset) + 1]) == 1)
			num_string[i++] = format[(*offset) + 1];
		else
			break ;
		(*offset)++;
	}
	options->width = ft_atoi(num_string);
	if (max_width_check(options) == -3)
		return (-3);
	return (0);
}

/*
If a precision is given with a numeric conversion (d, i, o, u, i, x, and X),
the 0 flag is ignored.
'-' overrides '0' if both are given.
'+' overrides space if both are used.
*/
int	check_flags(const char *format, unsigned long *offset, t_options *options)
{
	while (1)
	{
		if (format[*offset] == '\0')
			break ;
		else if (format[*(offset) + 1] == '#')
			options->hash = 1;
		else if (format[*(offset) + 1] == '0')
			options->zero = 1;
		else if (format[*(offset) + 1] == '-')
			options->dash = 1;
		else if (format[*(offset) + 1] == '+')
			options->plus = 1;
		else if (format[*(offset) + 1] == ' ')
			options->space = 1;
		else
			break ;
		(*offset)++;
	}
	flag_overrides(options);
	return (0);
}

int	options_hub(const char *format, unsigned long *offset, char **content,
	va_list ap)
{
	t_options	*options;
	int			irreg_content_len;

	irreg_content_len = 0;
	options = (t_options *)malloc(sizeof(t_options));
	if (options == NULL)
		error_handling(-2);
	initialize_options(options);
	initialize_flags(options);
	options->pair_found = 0;
	check_flags(format, offset, options);
	if (check_width(format, offset, options) == -3)
		return (-3);
	if (format[*(offset) + 1] == '.')
		check_precision(format, offset, options);
	else
		options->no_precision = 1;
	check_prefix(format, offset, options);
	if (save_conversion_type(format, offset, options) == -5)
		return (-5);
	irreg_content_len = check_conversion(offset, content, ap, options);
	if (irreg_content_len < -1)
		return (irreg_content_len);
	(*offset)++;
	return (irreg_content_len);
}
