/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:50:55 by lsalmi            #+#    #+#             */
/*   Updated: 2023/01/20 15:50:56 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a_b(t_node **head, char c)
{
	t_node	*new;
	t_node	*temp;

	if (!(*head) || !(*head)->next)
		return ;
	new = NULL;
	new = create_node((*head)->content);
	if (new == NULL)
		error();
	new->original_pos = (*head)->original_pos;
	new->final_pos = (*head)->final_pos;
	new->temp_pos = (*head)->temp_pos;
	temp = (*head)->next;
	new->next = NULL;
	add_to_back(&temp, new);
	del_first_node(head);
	*head = temp;
	if (c == 'a')
		ft_printf("ra\n");
	if (c == 'b')
		ft_printf("rb\n");
}

void	rotate_both(t_node **a, t_node **b)
{
	rotate_a_b(a, 'c');
	rotate_a_b(b, 'c');
	ft_printf("rr\n");
}

void	rev_rotate_a_b(t_node **head, char c)
{
	t_node	*new;
	t_node	*temp;

	if (!(*head) || !(*head)->next)
		return ;
	new = NULL;
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	new = create_node(temp->content);
	if (new == NULL)
		error();
	new->original_pos = temp->original_pos;
	new->final_pos = temp->final_pos;
	new->temp_pos = temp->temp_pos;
	new->next = *head;
	add_to_front(head, new);
	*head = new;
	del_last_node(head);
	if (c == 'a')
		ft_printf("rra\n");
	if (c == 'b')
		ft_printf("rrb\n");
}

void	rev_rotate_both(t_node **a, t_node **b)
{
	rev_rotate_a_b(a, 'c');
	rev_rotate_a_b(b, 'c');
	ft_printf("rrr\n");
}
