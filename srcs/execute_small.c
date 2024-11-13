/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:00:18 by lsalmi            #+#    #+#             */
/*   Updated: 2023/03/23 16:04:11 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	execute_small_ra_rb(t_node **a, t_node **b, int a_moves, int b_moves)
{
	while (a_moves != 0 && b_moves != 0)
	{
		rotate_both(a, b);
		a_moves--;
		b_moves--;
	}
	while (a_moves > 0)
	{
		rotate_a_b(a, 'a');
		a_moves--;
	}
	while (b_moves > 0)
	{
		rotate_a_b(b, 'b');
		b_moves--;
	}
	(*b)->temp_pos = 1;
	push_a(a, b);
}

void	execute_small_rra_rrb(t_node **a, t_node **b, int a_moves, int b_moves)
{
	while (a_moves != 0 && b_moves != 0)
	{
		rev_rotate_both(a, b);
		a_moves--;
		b_moves--;
	}
	while (a_moves > 0)
	{
		rev_rotate_a_b(a, 'a');
		a_moves--;
	}
	while (b_moves > 0)
	{
		rev_rotate_a_b(b, 'b');
		b_moves--;
	}
	(*b)->temp_pos = 1;
	push_a(a, b);
}

void	execute_small_ra_rrb(t_node **a, t_node **b, int b_moves)
{
	int	a_moves;

	a_moves = (*a)->ra_big;
	if (smallest_temp_pos(a) == 1)
		a_moves = (*a)->ra_small;
	while (a_moves > 0)
	{
		rotate_a_b(a, 'a');
		a_moves--;
	}
	while (b_moves > 0)
	{
		rev_rotate_a_b(b, 'b');
		b_moves--;
	}
	(*b)->temp_pos = 1;
	push_a(a, b);
}

void	execute_small_rra_rb(t_node **a, t_node **b, int b_moves)
{
	int	a_moves;

	a_moves = (*a)->rra_big;
	if (smallest_temp_pos(a) == 1)
		a_moves = (*a)->rra_small;
	while (a_moves > 0)
	{
		rev_rotate_a_b(a, 'a');
		a_moves--;
	}
	while (b_moves > 0)
	{
		rotate_a_b(b, 'b');
		b_moves--;
	}
	(*b)->temp_pos = 1;
	push_a(a, b);
}
