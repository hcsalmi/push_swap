/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:39:00 by lsalmi            #+#    #+#             */
/*   Updated: 2022/12/08 14:39:06 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*temp;

	temp = NULL;
	if (alst == NULL && new == NULL)
		return ;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	temp = *alst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}
