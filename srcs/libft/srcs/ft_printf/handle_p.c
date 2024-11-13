/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:02:10 by lsalmi            #+#    #+#             */
/*   Updated: 2022/06/24 15:02:13 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
A long hexadecimal number that represents a memory address.
*/
void	add_0x_to_address(char **content, t_options *options)
{
	char	*temp;

	temp = NULL;
	temp = *content;
	if (options->precision == 0 && options->conversion == 'p')
		*content = ft_strndup("0x", 2, 0);
	else if (options->uppercase == 1)
		*content = ft_strjoin("0X", temp);
	else
		*content = ft_strjoin("0x", temp);
	options->added_0x = 1;
	options->str_len = ft_strlen(*content);
	free(temp);
}

int	handle_p(char **content, va_list ap, t_options *options)
{
	options->base = 16;
	options->value = va_arg(ap, long);
	*content = ft_itoa_base((unsigned long)options->value, options->base,
			options->uppercase);
	if (*content == NULL)
		error_handling(-2);
	add_0x_to_address(content, options);
	if (options->width > 0)
		apply_width_oux(options, content);
	return (0);
}
