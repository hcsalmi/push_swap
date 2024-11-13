/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:15:47 by lsalmi            #+#    #+#             */
/*   Updated: 2023/03/23 12:15:52 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	zero_temp_pos(t_node **head)
{
	t_node	*temp;

	temp = *head;
	while (temp)
	{
		temp->temp_pos = 0;
		temp = temp->next;
	}
}

int	smallest_temp_pos(t_node **head)
{
	t_node	*temp;

	temp = *head;
	while (temp)
	{
		if (temp->temp_pos == 1)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	return_temp_pos(t_node **head, int final_position)
{
	t_node	*temp;
	int		location;

	if (!(*head) || !(*head)->next)
		return (0);
	temp = *head;
	location = 1;
	while (temp->next != NULL && temp->final_pos != final_position)
	{
		temp = temp->next;
		location++;
	}
	return (location);
}

int	last_node_final_pos(t_node **head)
{
	t_node	*temp;

	if (!(*head) || !(*head)->next)
		return (0);
	if (stack_size(*head) == 1)
		return ((*head)->final_pos);
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp->final_pos);
}
