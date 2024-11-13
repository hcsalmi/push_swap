/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:12:47 by lsalmi            #+#    #+#             */
/*   Updated: 2023/01/25 16:12:49 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_if_number(char **arr, int i)
{
	int	j;

	j = 0;
	while (arr[i] != NULL)
	{
		while (arr[i][j] != '\0')
		{
			if (j == 0 && (arr[i][j] == '+' || arr[i][j] == '-'))
				j++;
			if (ft_isdigit(arr[i][j]) == 1)
				j++;
			else
				return (-1);
		}
		j = 0;
		i++;
	}
	return (0);
}

int	check_if_duplicate(t_node *a_stack, int nb)
{
	t_node	*temp;

	temp = a_stack;
	if (stack_size(a_stack) == 1)
		return (0);
	while (temp->next != NULL)
	{
		if (temp->content == nb)
			return (-1);
		temp = temp->next;
	}
	return (0);
}
