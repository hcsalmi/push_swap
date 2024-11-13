/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:43:41 by lsalmi            #+#    #+#             */
/*   Updated: 2023/01/18 12:43:44 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_list(t_node *head)
{
	t_node	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	head = NULL;
}

int	stack_size(t_node *list)
{
	int		count;
	t_node	*temp;

	count = 0;
	if (!list)
		return (0);
	temp = list;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

void	add_to_front(t_node **head, t_node *new)
{
	if (head == NULL && new == NULL)
		return ;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	new->next = *head;
	*head = new;
}

void	add_to_back(t_node **head, t_node *new)
{
	t_node	*temp;

	temp = NULL;
	if (head == NULL && new == NULL)
		return ;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

t_node	*copy_list(t_node *list)
{
	t_node	*new;
	t_node	*new_head;

	new_head = NULL;
	if (!list || !(list->next))
		return (NULL);
	while (list)
	{
		new = create_node(list->content);
		if (new == NULL)
			error();
		new->original_pos = list->original_pos;
		new->final_pos = list->final_pos;
		add_to_back(&new_head, new);
		list = list->next;
	}
	free_list(list);
	return (new_head);
}
