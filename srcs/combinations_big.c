/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinations_big.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:52:16 by lsalmi            #+#    #+#             */
/*   Updated: 2023/03/24 17:52:18 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	shortest_option_big(t_strategy *options)
{
	if (options->big_rrb_ra < options->moves)
	{
		options->moves = options->big_rrb_ra;
		options->shortest = "big_ra_rrb";
	}
	if (options->big_rb_rra < options->moves)
	{
		options->moves = options->big_rb_rra;
		options->shortest = "big_rra_rb";
	}
	if (options->big_rb_ra < options->moves)
	{
		options->moves = options->big_rb_ra;
		options->shortest = "big_ra_rb";
	}
	if (options->big_rrb_rra < options->moves)
	{
		options->moves = options->big_rrb_rra;
		options->shortest = "big_rra_rrb";
	}
}

void	calculate_combinations_big(t_node **a, t_node **b, t_strategy *options)
{
	if (smallest_temp_pos(a) != 1)
	{
		options->big_rb_ra = (*b)->rb_big + (*a)->ra_small;
		options->big_rrb_ra = (*b)->rrb_big + (*a)->ra_small;
		options->big_rb_rra = (*b)->rb_big + (*a)->rra_small;
		options->big_rrb_rra = (*b)->rrb_big + (*a)->rra_small;
	}
	if (smallest_temp_pos(a) == 1)
	{
		options->big_rb_ra = (*b)->rb_big + (*a)->ra_big;
		options->big_rrb_ra = (*b)->rrb_big + (*a)->ra_big;
		options->big_rb_rra = (*b)->rb_big + (*a)->rra_big;
		options->big_rrb_rra = (*b)->rrb_big + (*a)->rra_big;
	}
}

/*
Handles cases where rr or rrr can be used instead of separate operations
ra, rb, rra, rrb. Calculates how many moves are left once
rr and rrr are applied.
*/
void	calculate_combinations_big_rr_rrr(t_node **a, t_node **b)
{
	int	diff;

	if ((*b)->rb_big > 0 && (*a)->ra_small > 0)
	{
		diff = (ft_abs((*b)->rb_big - (*a)->ra_small));
		(*b)->rr_big = ((*b)->rb_big + (*a)->ra_small - diff) / 2 + diff;
	}
	if (smallest_temp_pos(a) == 1 && ((*b)->rb_big > 0 && (*a)->ra_big > 0))
	{
		diff = (ft_abs((*b)->rb_big - (*a)->ra_big));
		(*b)->rr_big = ((*b)->rb_big + (*a)->ra_big - diff) / 2 + diff;
	}
	if ((*b)->rrb_big > 0 && (*a)->rra_small > 0)
	{
		diff = (ft_abs((*b)->rrb_big - (*a)->rra_small));
		(*b)->rrr_big = ((*b)->rrb_big + (*a)->rra_small - diff) / 2 + diff;
	}
	if (smallest_temp_pos(a) == 1 && (*b)->rrb_big > 0
		&& (*a)->rra_big > 0)
	{
		diff = (ft_abs((*b)->rrb_big - (*a)->rra_big));
		(*b)->rrr_big = ((*b)->rrb_big + (*a)->rra_big - diff) / 2 + diff;
	}
}

void	shortest_option_rr_rrr(t_node *b, t_strategy *options)
{
	if ((b)->rr_big < options->moves && (b)->rr_big > 0)
	{
		options->moves = (b)->rr_big;
		options->shortest = "big_rr";
	}
	if ((b)->rrr_big < options->moves && (b)->rrr_big > 0)
	{
		options->moves = (b)->rrr_big;
		options->shortest = "big_rrr";
	}
	if ((b)->rr_small < options->moves && (b)->rr_small > 0)
	{
		options->moves = (b)->rr_small;
		options->shortest = "small_rr";
	}
	if ((b)->rrr_small < options->moves && (b)->rrr_small > 0)
	{
		options->moves = (b)->rrr_small;
		options->shortest = "small_rrr";
	}
}
