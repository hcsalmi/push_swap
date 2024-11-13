/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:56:52 by lsalmi            #+#    #+#             */
/*   Updated: 2022/09/21 18:56:54 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	max_width_check(t_options *options)
{
	if (options->width > 100000000)
	{
		free (options);
		return (-3);
	}
	else
		return (0);
}

void	flag_overrides(t_options *options)
{
	if (options->dash == 1 && options->zero == 1)
		options->zero = 0;
	if (options->plus == 1 && options->space == 1)
		options->space = 0;
	if (options->hash == 0 && options->zero == 0 && options->dash == 0
		&& options->plus == 0 && options->space == 0)
		options->no_flags = 1;
}
