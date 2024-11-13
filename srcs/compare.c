/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:52:38 by lsalmi            #+#    #+#             */
/*   Updated: 2023/01/20 15:52:41 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_largest_pos(t_node **head)
{
	int		position;
	t_node	*temp;

	temp = *head;
	position = INT_MIN;
	while (temp)
	{
		if (temp->final_pos > position)
			position = temp->final_pos;
		temp = temp->next;
	}
	return (position);
}

int	find_smallest_pos(t_node **head)
{
	int		position;
	t_node	*temp;

	temp = *head;
	position = INT_MAX;
	while (temp)
	{
		if (temp->final_pos < position)
			position = temp->final_pos;
		temp = temp->next;
	}
	return (position);
}

/*
The start of the range is the difference between total_bs and the size of the
section being sorted (e.g. tens or forties).
Finding the largest position gives the end point of the range.
*/
int	find_smallest_pos_in_range(t_node **head, int chunk, int total_bs)
{
	int		pos;
	int		start;
	t_node	*temp;

	start = total_bs - chunk;
	temp = *head;
	pos = INT_MAX;
	while (temp)
	{
		if (temp->final_pos > start && temp->final_pos <= find_largest_pos(head)
			&& temp->final_pos < pos)
			pos = temp->final_pos;
		temp = temp->next;
	}
	temp = *head;
	while (temp)
	{
		temp->smallest = pos;
		temp = temp->next;
	}
	(*head)->smallest = pos;
	return (pos);
}
