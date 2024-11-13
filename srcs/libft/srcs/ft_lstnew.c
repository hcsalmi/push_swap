/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:28:16 by lsalmi            #+#    #+#             */
/*   Updated: 2021/11/24 18:25:01 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	node = NULL;
	node = (t_list *)malloc(sizeof(t_list) * content_size);
	if (node == NULL)
		return (NULL);
	if (content == NULL)
	{
		node->content = NULL;
		node->content_size = 0;
		node->next = NULL;
		return (node);
	}
	node->content = malloc(content_size);
	if (node->content == NULL)
		return (NULL);
	ft_memmove(node->content, content, content_size);
	node->content_size = content_size;
	node->next = NULL;
	return (node);
}
