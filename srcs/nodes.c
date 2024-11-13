/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:15:15 by lsalmi            #+#    #+#             */
/*   Updated: 2023/01/25 16:18:20 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	initialize_values(t_node **a, t_node **b)
{
	(*a)->ra_small = 0;
	(*a)->rra_small = 0;
	(*a)->ra_big = 0;
	(*a)->rra_big = 0;
	(*a)->smallest = 0;
	if (*b)
	{
		(*b)->rb_small = 0;
		(*b)->rrb_small = 0;
		(*b)->rb_big = 0;
		(*b)->rrb_big = 0;
		(*b)->rr_small = -1;
		(*b)->rrr_small = -1;
		(*b)->rr_big = -1;
		(*b)->rrr_big = -1;
		(*b)->smallest = 0;
	}
}

void	del_last_node(t_node **head)
{
	t_node	*temp;
	t_node	*second_last;

	second_last = NULL;
	temp = NULL;
	temp = *head;
	while (temp->next != NULL)
	{
		second_last = temp;
		temp = temp->next;
	}
	second_last->next = NULL;
	free(temp);
}

void	del_first_node(t_node **head)
{
	t_node	*temp;

	temp = NULL;
	temp = *head;
	*head = (*head)->next;
	free(temp);
}

t_node	*create_node(int content)
{
	t_node	*new;

	new = NULL;
	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->temp_pos = 0;
	new->final_pos = 0;
	return (new);
}

void	create_stack(char **arr, int i, int pos, t_node **head)
{
	t_node	*node;
	long	result;

	node = NULL;
	while (arr[i])
	{
		result = ft_atol(arr[i]);
		if (result > 2147483647 || result < -2147483648)
			error();
		node = create_node(result);
		if (node == NULL)
			error();
		i++;
		node->original_pos = pos++;
		add_to_back(head, node);
		if (check_if_duplicate(*head, node->content) == -1)
			error();
	}
}
