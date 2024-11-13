/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:19:15 by lsalmi            #+#    #+#             */
/*   Updated: 2021/11/24 13:03:32 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*temp;
	t_list	*newnode;

	if (lst == NULL)
		return (NULL);
	temp = f(lst);
	newnode = ft_lstnew(temp->content, temp->content_size);
	if (newnode == NULL)
		return (NULL);
	start = newnode;
	lst = lst->next;
	while (lst != NULL)
	{
		temp = f(lst);
		newnode->next = ft_lstnew(temp->content, temp->content_size);
		if (newnode->next == NULL)
			return (NULL);
		newnode = newnode->next;
		lst = lst->next;
	}
	return (start);
}
