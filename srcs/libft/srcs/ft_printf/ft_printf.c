/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:36:41 by lsalmi            #+#    #+#             */
/*   Updated: 2022/06/16 15:36:43 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* The va_arg() macro returns the current argument.
The va_end() and va_start() macros return no values.
ft_printf returns the number of characters that are printed.
If there is an error, it returns a negative value.
*/
int	gather_string(const char *format, unsigned long *offset,
	char **content)
{
	size_t			len;
	unsigned long	start;

	start = *offset;
	while (format[*offset] != '%' && format[*offset] != '\0')
		(*offset)++;
	len = *offset - start;
	*content = ft_strndup(format, len, start);
	if (*content == NULL)
		error_handling(-2);
	return (0);
}

int	create_node_or_not(int *flag, t_data **head, char **content,
	int irreg_len)
{
	if (irreg_len < -1)
		return (irreg_len);
	if ((irreg_len) != -1)
		create_node_hub(flag, head, content, irreg_len);
	else
	{
		free(*content);
		*content = NULL;
	}
	return (0);
}

int	move_offset(const char *format, unsigned long *offset, char **content,
	va_list ap)
{
	int	irreg_len;

	(*offset)--;
	irreg_len = options_hub(format, offset, content, ap);
	return (irreg_len);
}

/*
Percentage case:
Covers cases where odd number of percentage symbols has been found and the
format string continues. First creates nodes for the percentage symbols
as required and then continues looking.
*/
int	parse_string(const char *form, t_data **head, va_list ap,
		unsigned long offs)
{
	char	*content;
	int		head_flag;
	int		irreg_len;

	initialize_variables(&content, &head_flag, &irreg_len);
	while (form[offs] != '\0')
	{
		if (form[offs] == '%' && form[offs + 1] == '\0')
			break ;
		else if (form[offs] == '%' && form[offs + 1] == '%')
		{
			if (handle_prc(form, &offs, &content) == -1 && (form[offs] != '\0'))
			{
				create_node_hub(&head_flag, head, &content, irreg_len);
				irreg_len = move_offset(form, &offs, &content, ap);
			}
		}
		else if (form[offs] == '%')
			irreg_len = options_hub(form, &offs, &content, ap);
		else
			irreg_len = gather_string(form, &offs, &content);
		if (create_node_or_not(&head_flag, head, &content, irreg_len) < -1)
			return (irreg_len);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	t_data			*head;
	int				ret;
	unsigned long	offset;

	ret = 0;
	offset = 0;
	head = NULL;
	if (ft_strlen(format) == 0)
		return (0);
	va_start(ap, format);
	ret = parse_string(format, &head, ap, offset);
	if (ret < 0)
	{
		error_handling(ret);
		if (head)
			free_whole_list(head->head);
		va_end(ap);
		return (ret);
	}
	ret = print_list(head);
	if (head)
		free_whole_list(head->head);
	va_end(ap);
	return (ret);
}
