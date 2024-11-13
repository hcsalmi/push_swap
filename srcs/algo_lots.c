/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_lots.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:21:54 by lsalmi            #+#    #+#             */
/*   Updated: 2023/02/28 12:29:09 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Sort numbers back to A in sections starting from the largest number.
*/
void	sort_to_a(t_node **a, t_node **b, int chunk)
{
	int	total_bs;
	int	i;
	int	forties;
	int	tens;

	i = chunk;
	total_bs = stack_size(*b) + 3;
	forties = count_chunks(&total_bs, 40);
	tens = count_chunks(&total_bs, 10);
	total_bs = stack_size(*b);
	while (i > 0)
	{
		perform_strategy(a, b, chunk, total_bs);
		i--;
	}
	total_bs = total_bs - chunk;
	while (tens > 0)
		sort_ten(a, b, &tens, &total_bs);
	while (forties > 0)
		sort_forty(a, b, &forties, &total_bs);
}

/*
Pushes the content of A to B in sections. Leaves three largest numbers in A.
*/
void	sort_to_b(t_node **a, t_node **b, int total_bs, int *size)
{
	int	i;
	int	forties;
	int	tens;

	i = 0;
	forties = count_chunks(&total_bs, 40);
	tens = count_chunks(&total_bs, 10);
	while (forties-- > 0)
	{
		i = i + 40;
		push_chunk(a, b, i, 40);
	}
	while (tens-- > 0)
	{
		i = i + 10;
		push_chunk(a, b, i, 10);
	}
	if (stack_size(*a) > 3 && stack_size(*a) < 13)
	{
		*size = stack_size(*a) - 3;
		leave_three(a, b, stack_size(*a) + stack_size(*b) - 3);
	}
	else
		*size = stack_size(*a) - 3;
}

void	run_algo_lots(t_node **a, t_node **b)
{
	int	size;
	int	total_bs;

	total_bs = stack_size(*a);
	size = stack_size(*a);
	sort_to_b(a, b, total_bs, &size);
	run_algo_three(a, 'a');
	sort_to_a(a, b, size);
	rotate_final_list(a);
}
