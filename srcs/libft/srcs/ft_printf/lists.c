/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:31:22 by lsalmi            #+#    #+#             */
/*   Updated: 2022/06/09 14:31:26 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	free_whole_list(t_data *head)
{
	if (head)
	{
		if (head->content != NULL)
		{
			free(head->content);
			head->content = NULL;
		}
		free_whole_list(head->next);
		free(head);
	}
}

int	print_list(t_data *node)
{
	int	ret;

	ret = 0;
	while (node != NULL)
	{
		if (node->irreg_len != 0)
		{
			write(1, node->content, node->irreg_len);
			ret = ret + node->irreg_len;
		}
		else
		{
			write(1, node->content, ft_strlen(node->content));
			ret = ret + ft_strlen(node->content);
		}
		node = node->next;
	}
	return (ret);
}

t_data	*ft_data_push_back(t_data **head, char *content, int irreg_len,
	int *flag)
{
	t_data	*ptr;
	t_data	*new;

	new = NULL;
	ptr = NULL;
	ptr = *head;
	new = (t_data *)malloc(sizeof(t_data));
	if (new == NULL)
		return (NULL);
	initialize_node(new, *head);
	new->content = content;
	new->irreg_len = irreg_len;
	if (content != NULL && irreg_len == 0)
		new->content_len = ft_strlen(content);
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new;
	new->head_flag = *flag;
	return (new);
}

/*
Flag determines whether it is the first node or not.
*/
int	create_node_hub(int *flag, t_data **head, char **content,
	int irreg_len)
{
	if (*flag == 0)
	{
		*head = (t_data *)malloc(sizeof(t_data));
		if (*head == NULL)
			error_handling(-2);
		initialize_head(head, *content, irreg_len, flag);
	}
	else
		ft_data_push_back(head, *content, irreg_len, flag);
	*flag = 1;
	(*head)->head_flag = *flag;
	return (0);
}
