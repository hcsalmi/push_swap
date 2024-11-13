/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:15:32 by lsalmi            #+#    #+#             */
/*   Updated: 2023/01/18 17:15:34 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a_b(t_node **head, char c)
{
	t_node	*temp;

	if (!(*head) || !(*head)->next)
		return ;
	temp = (*head)->next;
	(*head)->next = temp->next;
	temp->next = *head;
	*head = temp;
	if (c == 'a')
		ft_printf("sa\n");
	if (c == 'b')
		ft_printf("sb\n");
}

void	push_b(t_node **a, t_node **b)
{
	t_node	*new;

	if (!(*a))
		return ;
	new = create_node((*a)->content);
	if (new == NULL)
		error();
	new->original_pos = (*a)->original_pos;
	new->final_pos = (*a)->final_pos;
	new->temp_pos = (*a)->temp_pos;
	if (!(*b))
		*b = new;
	else
	{
		new->next = *b;
		*b = new;
	}
	del_first_node(a);
	ft_printf("pb\n");
}

void	push_a(t_node **a, t_node **b)
{
	t_node	*new;

	if (!(*b))
		return ;
	new = create_node((*b)->content);
	if (new == NULL)
		error();
	new->original_pos = (*b)->original_pos;
	new->final_pos = (*b)->final_pos;
	new->temp_pos = (*b)->temp_pos;
	if (!(*a))
	{
		*a = new;
		(*a)->next = NULL;
	}
	else
	{
		new->next = *a;
		*a = new;
	}
	del_first_node(b);
	ft_printf("pa\n");
}
