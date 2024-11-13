/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinations_small.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:49:19 by lsalmi            #+#    #+#             */
/*   Updated: 2023/03/24 17:49:20 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	shortest_option_small(t_strategy *options)
{
	options->shortest = "small_rra_rb";
	options->moves = options->small_rb_rra;
	if (options->small_rrb_ra < options->moves)
	{
		options->moves = options->small_rrb_ra;
		options->shortest = "small_ra_rrb";
	}
	if (options->small_rb_ra < options->moves)
	{
		options->moves = options->small_rb_ra;
		options->shortest = "small_ra_rb";
	}
	if (options->small_rrb_rra < options->moves)
	{
		options->moves = options->small_rrb_rra;
		options->shortest = "small_rra_rrb";
	}
}

void	calculate_combinations_small(t_node **a, t_node **b,
		t_strategy *options)
{
	if (smallest_temp_pos(a) != 1)
	{
		options->small_rb_ra = (*b)->rb_small + (*a)->ra_big;
		options->small_rrb_ra = (*b)->rrb_small + (*a)->ra_big;
		options->small_rb_rra = (*b)->rb_small + (*a)->rra_big;
		options->small_rrb_rra = (*b)->rrb_small + (*a)->rra_big;
	}
	if (smallest_temp_pos(a) == 1)
	{
		options->small_rb_ra = (*b)->rb_small + (*a)->ra_small;
		options->small_rrb_ra = (*b)->rrb_small + (*a)->ra_small;
		options->small_rb_rra = (*b)->rb_small + (*a)->rra_small;
		options->small_rrb_rra = (*b)->rrb_small + (*a)->rra_small;
	}
}

/*
Handles cases where rr or rrr can be used instead of separate operations
ra, rb, rra, rrb. Calculates how many moves are left once
rr and rrr are applied.
*/
void	calculate_combinations_small_rr_rrr(t_node **a, t_node **b)
{
	int		diff;

	if ((*b)->rb_small > 0 && (*a)->ra_big > 0)
	{
		diff = (ft_abs((*b)->rb_small - (*a)->ra_big));
		(*b)->rr_small = ((*b)->rb_small + (*a)->ra_big - diff) / 2 + diff;
	}
	if (smallest_temp_pos(a) == 1 && (*b)->rb_small > 0 && (*a)->ra_small > 0)
	{
		diff = (ft_abs((*b)->rb_small - (*a)->ra_small));
		(*b)->rr_small = ((*b)->rb_small + (*a)->ra_small - diff) / 2 + diff;
	}
	if ((*b)->rrb_small > 0 && (*a)->rra_big > 0)
	{
		diff = (ft_abs((*b)->rrb_small - (*a)->rra_big));
		(*b)->rrr_small = ((*b)->rrb_small + (*a)->rra_big - diff) / 2 + diff;
	}
	if (smallest_temp_pos(a) == 1 && ((*b)->rrb_small > 0
			&& (*a)->rra_small > 0))
	{
		diff = (ft_abs((*b)->rrb_small - (*a)->rra_small));
		(*b)->rrr_small = ((*b)->rrb_small + (*a)->rra_small - diff) / 2 + diff;
	}
}
