/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:44:34 by lsalmi            #+#    #+#             */
/*   Updated: 2023/01/17 12:44:37 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit (0);
}

void	handle_single_string(char *str, t_node **a)
{
	char	**arr;

	if (str[0] == '\0')
		exit (0);
	arr = NULL;
	arr = ft_strsplit(str, ' ');
	if (arr[0] == NULL)
		exit (0);
	if (check_if_number(arr, 0) == -1)
	{
		ft_free_char_array(arr);
		error();
	}
	create_stack(arr, 0, 1, a);
	ft_free_char_array(arr);
}

void	rotate_final_list(t_node **a)
{
	while (return_temp_pos(a, 1) != 1)
	{
		if (return_temp_pos(a, 1) <= stack_size(*a) / 2 + 1)
			rotate_a_b(a, 'a');
		else
			rev_rotate_a_b(a, 'a');
	}
}

/*
Chooses algorithm based on the size of A stack.
*/
void	choose_algo(t_node **a, t_node **b)
{
	int		size;

	if (stack_size(*a) == 1 || create_copy(a) == 1)
		return ;
	size = stack_size(*a);
	if (size == 2)
		run_algo_two(a, 'a');
	else if (size == 3)
		run_algo_three(a, 'a');
	else
		run_algo_lots(a, b);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	if (argc < 2)
		return (-1);
	a = NULL;
	b = NULL;
	if (argc == 2)
		handle_single_string(argv[1], &a);
	else if (argc > 2)
	{
		if (check_if_number(argv, 1) == -1)
			error();
		create_stack(argv, 1, 1, &a);
	}
	choose_algo(&a, &b);
	free_list(a);
	return (0);
}
