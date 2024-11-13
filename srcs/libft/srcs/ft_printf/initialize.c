/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:28:37 by lsalmi            #+#    #+#             */
/*   Updated: 2022/06/09 14:28:41 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	initialize_options(t_options *options)
{
	options->hash = 0;
	options->zero = 0;
	options->dash = 0;
	options->plus = 0;
	options->space = 0;
	options->hh = 0;
	options->h = 0;
	options->l = 0;
	options->ll = 0;
	options->l_caps = 0;
	options->base = 10;
	options->width = -1;
	options->precision = 1;
	options->preci_f = 6;
	options->preci_original = -1;
	options->rounding = 0;
	options->uppercase = 0;
	options->str_len = 0;
	options->edge_case_len = 0;
	options->float_value = 0;
	options->value = 0;
}

void	initialize_flags(t_options *options)
{
	options->zero_padded = 0;
	options->space_padded = 0;
	options->space_added = 0;
	options->sign_added = 0;
	options->added_0x = 0;
	options->pair_found = 0;
	options->inf_nan = 0;
	options->nan = 0;
	options->no_flags = 0;
	options->is_neg = 0;
	options->no_precision = 0;
	options->no_width = 0;
}

void	initialize_node(t_data *new, t_data *head)
{
	new->next = NULL;
	new->content = NULL;
	new->head = NULL;
	new->irreg_len = head->irreg_len;
	new->content_len = 0;
	new->head = head;
}

void	initialize_head(t_data **head, char *content, int irreg_len, int *flag)
{
	(*head)->next = NULL;
	(*head)->content = NULL;
	(*head)->content = content;
	(*head)->irreg_len = irreg_len;
	if ((*head)->irreg_len == 0 && content != NULL)
		(*head)->content_len = ft_strlen(content);
	if (content == NULL)
		(*head)->content_len = 6;
	(*head)->head = NULL;
	(*head)->head = *head;
	(*head)->head_flag = *flag;
}

void	initialize_variables(char **content, int *flag, int *irreg_len)
{
	*content = NULL;
	*flag = 0;
	*irreg_len = 0;
}
