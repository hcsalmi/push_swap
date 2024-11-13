/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:19:33 by lsalmi            #+#    #+#             */
/*   Updated: 2023/04/12 15:19:35 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_forty(t_node **a, t_node **b, int *forties, int *total_bs)
{
	int	chunk;
	int	i;

	chunk = 40;
	i = 40;
	zero_temp_pos(a);
	(*b)->smallest = 0;
	if (*b)
		find_smallest_pos_in_range(b, chunk, *total_bs);
	while (*b && i > 0)
	{
		perform_strategy(a, b, 40, *total_bs);
		i--;
	}
	(*forties)--;
	*total_bs = *total_bs - 40;
}

void	sort_ten(t_node **a, t_node **b, int *tens, int *total_bs)
{
	int	chunk;
	int	i;

	chunk = 10;
	i = 10;
	zero_temp_pos(a);
	(*b)->smallest = 0;
	if (*b)
		find_smallest_pos_in_range(b, chunk, *total_bs);
	while (*b && i > 0)
	{
		perform_strategy(a, b, 10, *total_bs);
		i--;
	}
	(*tens)--;
	*total_bs = *total_bs - 10;
}

int	leave_three(t_node **a, t_node **b, int index)
{
	while (stack_size(*a) > 3)
	{
		if ((*a)->final_pos <= index)
			push_b(a, b);
		else
			rotate_a_b(a, 'a');
	}
	return (0);
}

int	push_chunk(t_node **a, t_node **b, int index, int chunk)
{
	int	pushes;

	pushes = 0;
	while (pushes < chunk)
	{
		if ((*a)->final_pos <= index)
		{
			push_b(a, b);
			pushes++;
		}
		else
			rotate_a_b(a, 'a');
	}
	return (0);
}

/*
Counts how many chunks of forty or ten are to be pushed to B stack.
*/
int	count_chunks(int *total_bs, int chunk)
{
	int	counter;

	counter = 0;
	while (*total_bs >= chunk + 3)
	{
		counter++;
		*total_bs = *total_bs - chunk;
	}
	return (counter);
}
