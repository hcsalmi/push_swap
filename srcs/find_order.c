/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:48:35 by lsalmi            #+#    #+#             */
/*   Updated: 2023/04/12 16:48:36 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	save_order_to_struct(t_node **head, int *solution)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = *head;
	while (i < stack_size(*head))
	{
		while (temp)
		{
			while (solution[i] != temp->original_pos)
				temp = temp->next;
			temp->final_pos = i + 1;
			break ;
		}
		i++;
		temp = *head;
	}
}

int	comp_to_original(t_node *a, int *solution)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = a;
	while (i < stack_size(a))
	{
		if (solution[i] == temp->original_pos)
		{
			i++;
			temp = temp->next;
		}
		else
			return (0);
	}
	return (1);
}

void	swap_until_sorted(t_node **head)
{
	int		swapped;
	t_node	*temp;

	temp = *head;
	while (1)
	{
		swapped = 0;
		while (temp->next)
		{
			if (temp->content > temp->next->content)
			{
				ft_swap(&(temp->content), &(temp->next->content));
				ft_swap(&(temp->original_pos), &(temp->next->original_pos));
				swapped = 1;
			}
			temp = temp->next;
		}
		if (swapped == 0)
			break ;
		temp = *head;
	}
}

/*
Creates an int array of the correct order of nodes.
*/
int	*find_right_order(t_node **head)
{
	t_node	*temp;
	int		*solution;
	int		i;

	if (!(*head))
		NULL;
	temp = *head;
	swap_until_sorted(head);
	solution = (int *)malloc(sizeof(int) * stack_size(temp));
	if (solution == NULL)
		return (NULL);
	i = 0;
	while (temp)
	{
		solution[i] = temp->original_pos;
		temp->final_pos = i + 1;
		i++;
		temp = temp->next;
	}
	return (solution);
}

/*
Checks if the order is correct to begin with.
Creates a copy of the list to find out final positions and saves them in the
struct.
*/
int	create_copy(t_node **a)
{
	t_node	*copy;
	int		*solution;

	copy = copy_list(*a);
	solution = find_right_order(&copy);
	if (solution == NULL)
		error();
	if (comp_to_original(*a, solution) == 1)
	{
		free_list(copy);
		free(solution);
		return (1);
	}
	if ((*a)->final_pos == 0)
		save_order_to_struct(a, solution);
	free_list(copy);
	free(solution);
	return (0);
}
