/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:47:17 by lsalmi            #+#    #+#             */
/*   Updated: 2023/04/14 13:25:26 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "../srcs/libft/includes/libft.h"
# include "../srcs/libft/includes/ft_printf.h"

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	int				original_pos;
	int				final_pos;
	int				temp_pos;
	int				smallest;
	int				ra_small;
	int				rra_small;
	int				ra_big;
	int				rra_big;
	int				rb_small;
	int				rrb_small;
	int				rb_big;
	int				rrb_big;
	int				rr_small;
	int				rrr_small;
	int				rr_big;
	int				rrr_big;
}				t_node;

typedef struct s_strategy
{
	int		small_rb_ra;
	int		small_rrb_ra;
	int		small_rb_rra;
	int		small_rrb_rra;
	int		big_rb_ra;
	int		big_rrb_ra;
	int		big_rb_rra;
	int		big_rrb_rra;
	char	*shortest;
	int		moves;
}			t_strategy;

void	add_to_back(t_node **head, t_node *new);
void	add_to_front(t_node **head, t_node *new);
long	ft_atol(char *str);
void	calculate_combinations_big(t_node **a, t_node **b, t_strategy *options);
void	calculate_combinations_big_rr_rrr(t_node **a, t_node **b);
void	calculate_combinations_small(t_node **a, t_node **b,
			t_strategy *options);
void	calculate_combinations_small_rr_rrr(t_node **a, t_node **b);
int		check_if_duplicate(t_node *a_stack, int nb);
int		check_if_number(char **arr, int i);
t_node	*copy_list(t_node *list);
int		count_chunks(int *total_bs, int chunk);
void	count_moves_a_smallest_sorted(t_node **a, t_node **b);
void	count_moves_a_smallest_unsorted(t_node **a);
void	count_moves_b(t_node **b, int chunk, int total_bs);
int		create_copy(t_node **a);
t_node	*create_node(int content);
void	create_stack(char **arr, int i, int pos, t_node **head);
void	del_first_node(t_node **head);
void	del_last_node(t_node **head);
void	error(void);
void	execute_big_ra_rb(t_node **a, t_node **b, int a_moves, int b_moves);
void	execute_big_ra_rrb(t_node **a, t_node **b, int b_moves);
void	execute_big_rra_rb(t_node **a, t_node **b, int b_moves);
void	execute_big_rra_rrb(t_node **a, t_node **b, int a_moves, int b_moves);
void	execute_small_ra_rb(t_node **a, t_node **b, int a_moves, int b_moves);
void	execute_small_ra_rrb(t_node **a, t_node **b, int b_moves);
void	execute_small_rra_rb(t_node **a, t_node **b, int b_moves);
void	execute_small_rra_rrb(t_node **a, t_node **b, int a_moves, int b_moves);
int		find_largest_pos(t_node **head);
int		find_smallest_pos(t_node **head);
int		find_smallest_pos_in_range(t_node **head, int chunk, int total_bs);
void	free_list(t_node *head);
void	initialize_values(t_node **a, t_node **b);
int		leave_three(t_node **a, t_node **b, int index);
void	perform_strategy(t_node **a, t_node **b, int chunk, int total_bs);
void	push_a(t_node **a, t_node **b);
void	push_b(t_node **a, t_node **b);
int		push_chunk(t_node **a, t_node **b, int index, int chunk);
int		return_temp_pos(t_node **head, int final_position);
void	rev_rotate_a_b(t_node **head, char c);
void	rev_rotate_both(t_node **a, t_node **b);
void	rotate_a_b(t_node **head, char c);
void	rotate_both(t_node **a, t_node **b);
void	rotate_final_list(t_node **a);
void	run_algo_lots(t_node **a, t_node **b);
void	run_algo_three(t_node **head, char c);
void	run_algo_two(t_node **a, char c);
void	shortest_option_big(t_strategy *options);
void	shortest_option_rr_rrr(t_node *b, t_strategy *options);
void	shortest_option_small(t_strategy *options);
int		smallest_temp_pos(t_node **head);
void	sort_forty(t_node **a, t_node **b, int *forties, int *total_bs);
void	sort_ten(t_node **a, t_node **b, int *tens, int *total_bs);
int		stack_size(t_node *list);
void	swap_a_b(t_node **head, char c);
void	zero_temp_pos(t_node **head);

#endif
