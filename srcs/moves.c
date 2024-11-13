/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:35:08 by lsalmi            #+#    #+#             */
/*   Updated: 2023/04/12 15:35:10 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Checks whether the specified position is in the stack.
*/
int	is_in_stack(t_node **head, int position)
{
	t_node	*temp;

	temp = *head;
	while (temp)
	{
		if (temp->final_pos == position)
			return (1);
		else
			temp = temp->next;
	}
	return (0);
}

/*
Calculates the moves to position smallest/largest value on top of B stack.
*/
void	count_moves_b(t_node **b, int chunk, int total_bs)
{
	int	small_b;
	int	big_b;
	int	pos_big_b;
	int	pos_small_b;

	small_b = find_smallest_pos_in_range(b, chunk, total_bs);
	big_b = find_largest_pos(b);
	pos_big_b = return_temp_pos(b, big_b);
	pos_small_b = return_temp_pos(b, small_b);
	(*b)->rrb_small = stack_size(*b) - pos_small_b + 1;
	(*b)->rrb_big = stack_size(*b) - pos_big_b + 1;
	if (pos_small_b != 0)
		(*b)->rb_small = ft_abs(1 - pos_small_b);
	else
		(*b)->rb_small = 0;
	if (pos_big_b != 0)
		(*b)->rb_big = ft_abs(1 - pos_big_b);
	else
		(*b)->rb_big = 0;
}

/*
Counts the moves required to move A's largest and smallest to desired positions.
The smallest needs to be on the top of the stack and the largest needs to be at
the bottom. This applies while the smallest (in current range) from B stack
has not been moved to A stack.
*/
void	count_moves_a_smallest_unsorted(t_node **a)
{
	int	small_a;
	int	big_a;
	int	pos_big_a;
	int	pos_small_a;

	small_a = find_smallest_pos(a);
	big_a = find_largest_pos(a);
	pos_small_a = return_temp_pos(a, small_a);
	pos_big_a = return_temp_pos(a, big_a);
	(*a)->rra_small = stack_size(*a) - pos_small_a + 1;
	(*a)->rra_big = stack_size(*a) - pos_big_a;
	if (pos_small_a != 0)
		(*a)->ra_small = ft_abs(1 - pos_small_a);
	else
		(*a)->ra_small = 0;
	if (pos_big_a != 0)
		(*a)->ra_big = ft_abs(1 - pos_big_a) + 1;
	else
		(*a)->ra_big = 0;
}

/*
Counts the moves required to move A's largest and smallest to desired positions.
The largest needs to be on the top of the stack and the smallest needs to be at
the bottom. This applies while the smallest (in current range) from B stack has
already been moved to A stack.
*/
void	count_moves_a_smallest_sorted(t_node **a, t_node **b)
{
	int	small_a;
	int	big_a;
	int	pos_big_a;
	int	pos_small_a;

	small_a = (*b)->smallest - 1;
	if (is_in_stack(a, small_a) == 0)
	{
		count_moves_a_smallest_unsorted(a);
		return ;
	}
	big_a = find_largest_pos(b) + 1;
	pos_small_a = return_temp_pos(a, small_a);
	pos_big_a = return_temp_pos(a, big_a);
	(*a)->rra_small = stack_size(*a) - pos_small_a;
	(*a)->rra_big = stack_size(*a) - pos_big_a + 1;
	if (pos_small_a != 0)
		(*a)->ra_small = ft_abs(1 - pos_small_a) + 1;
	else
		(*a)->ra_small = 1;
	if (pos_big_a != 0)
		(*a)->ra_big = ft_abs(1 - pos_big_a);
	else
		(*a)->ra_big = 0;
}
