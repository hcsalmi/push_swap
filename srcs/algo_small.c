/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:12:29 by lsalmi            #+#    #+#             */
/*   Updated: 2023/03/23 15:12:36 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Stack of three:
Assigns temporary positions based on relative final positions.
*/
void	assign_temp_positions(t_node **head)
{
	if (((*head)->final_pos < (*head)->next->final_pos)
		&& ((*head)->final_pos < (*head)->next->next->final_pos))
		(*head)->temp_pos = 1;
	else if (((*head)->final_pos < (*head)->next->final_pos)
		|| ((*head)->final_pos < (*head)->next->next->final_pos))
		(*head)->temp_pos = 2;
	else if (((*head)->final_pos > (*head)->next->final_pos)
		&& ((*head)->final_pos > (*head)->next->next->final_pos))
		(*head)->temp_pos = 3;
}

void	run_algo_two(t_node **a, char c)
{
	if ((*a)->content < (*a)->next->content)
		return ;
	else
		rotate_a_b(a, c);
}

/*
Uses temporary positions to sort stack of three.
*/
void	run_algo_three(t_node **head, char c)
{
	if (create_copy(head) == 1)
		return ;
	assign_temp_positions(head);
	if ((*head)->temp_pos == 1)
	{
		rev_rotate_a_b(head, c);
		swap_a_b(head, c);
	}
	else if ((*head)->temp_pos == 2 && ((*head)->next->final_pos
			> (*head)->next->next->final_pos))
		rev_rotate_a_b(head, c);
	else if ((*head)->temp_pos == 2)
		swap_a_b(head, c);
	else if ((*head)->temp_pos == 3 && ((*head)->next->final_pos
			< (*head)->next->next->final_pos))
		rotate_a_b(head, c);
	else
	{
		rotate_a_b(head, c);
		swap_a_b(head, c);
	}
	zero_temp_pos(head);
}
