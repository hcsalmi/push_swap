/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:29:11 by lsalmi            #+#    #+#             */
/*   Updated: 2023/04/12 15:29:12 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_big(char *strategy, t_node **a, t_node **b)
{
	if (ft_strequ(strategy, "big_rra_rb") == 1)
		execute_big_rra_rb(a, b, (*b)->rb_big);
	if (ft_strequ(strategy, "big_ra_rrb") == 1)
		execute_big_ra_rrb(a, b, (*b)->rrb_big);
	if (ft_strequ(strategy, "big_ra_rb") == 1
		|| ft_strequ(strategy, "big_rr") == 1)
	{
		if (smallest_temp_pos(a) == 1)
			execute_big_ra_rb(a, b, (*a)->ra_big, (*b)->rb_big);
		else
			execute_big_ra_rb(a, b, (*a)->ra_small, (*b)->rb_big);
	}
	if (ft_strequ(strategy, "big_rra_rrb") == 1
		|| ft_strequ(strategy, "big_rrr") == 1)
	{
		if (smallest_temp_pos(a) == 1)
			execute_big_rra_rrb(a, b, (*a)->rra_big, (*b)->rrb_big);
		else
			execute_big_rra_rrb(a, b, (*a)->rra_small, (*b)->rrb_big);
	}
}

void	push_small(char *strategy, t_node **a, t_node **b)
{
	if (ft_strequ(strategy, "small_rra_rb") == 1)
		execute_small_rra_rb(a, b, (*b)->rb_small);
	if (ft_strequ(strategy, "small_ra_rrb") == 1)
		execute_small_ra_rrb(a, b, (*b)->rrb_small);
	if (ft_strequ(strategy, "small_ra_rb") == 1
		|| ft_strequ(strategy, "small_rr") == 1)
	{
		if (smallest_temp_pos(a) == 1)
			execute_small_ra_rb(a, b, (*a)->ra_small, (*b)->rb_small);
		else
			execute_small_ra_rb(a, b, (*a)->ra_big, (*b)->rb_small);
	}
	if (ft_strequ(strategy, "small_rra_rrb") == 1
		|| ft_strequ(strategy, "small_rrr") == 1)
	{
		if (smallest_temp_pos(a) == 1)
			execute_small_rra_rrb(a, b, (*a)->rra_small, (*b)->rrb_small);
		else
			execute_small_rra_rrb(a, b, (*a)->rra_big, (*b)->rrb_small);
	}
}

char	*compare_routes(t_node **a, t_node **b)
{
	char		*solution;
	t_strategy	*options;

	options = (t_strategy *)malloc(sizeof(t_strategy));
	if (options == NULL)
	{
		free_list(*a);
		free_list(*b);
		return (NULL);
	}
	calculate_combinations_small(a, b, options);
	calculate_combinations_big(a, b, options);
	calculate_combinations_big_rr_rrr(a, b);
	calculate_combinations_small_rr_rrr(a, b);
	shortest_option_small(options);
	shortest_option_big(options);
	shortest_option_rr_rrr(*b, options);
	solution = options->shortest;
	free(options);
	return (solution);
}

void	perform_strategy(t_node **a, t_node **b, int chunk, int total_bs)
{
	char	*strategy;

	initialize_values(a, b);
	(*b)->smallest = find_smallest_pos_in_range(b, chunk, total_bs);
	if (smallest_temp_pos(a) != 1)
		count_moves_a_smallest_unsorted(a);
	else
		count_moves_a_smallest_sorted(a, b);
	count_moves_b(b, chunk, total_bs);
	strategy = compare_routes(a, b);
	if (strategy == NULL)
		error();
	if (ft_strncmp(strategy, "small", 5) == 0)
		push_small(strategy, a, b);
	else
		push_big(strategy, a, b);
}
