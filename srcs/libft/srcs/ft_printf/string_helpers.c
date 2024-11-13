/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:57:21 by lsalmi            #+#    #+#             */
/*   Updated: 2022/08/04 17:57:27 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	join_strings_cs(t_options *options, char **content, char **temp,
	char **new_content)
{
	if (options->dash == 0)
		(*new_content) = ft_strjoin((*temp), *content);
	else
		(*new_content) = ft_strjoin(*content, (*temp));
}

char	*ft_create_pad_str(size_t len, char c)
{
	char			*temp;
	unsigned long	i;

	i = 0;
	temp = (char *)malloc(sizeof(char) * len + 1);
	if (temp == NULL)
		return (NULL);
	while (i < len)
	{
		temp[i] = c;
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

/*
Includes a condition to specify that len is 0 if content is '\0' (prevents an
extra null terminator).
*/
char	*ft_strndup(const char *s1, size_t len, unsigned long start)
{
	char			*dest;
	unsigned long	i;

	i = 0;
	if (len == 1 && s1[0] == '\0')
		len = 0;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (i < len)
	{
		dest[i] = s1[i + start];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*strjoin_null_char(const char *str, t_options *options, size_t len)
{
	char	*arr;
	int		i;
	int		j;

	arr = (char *)malloc(sizeof(char) * len);
	if (arr == NULL)
		return (NULL);
	if (options->dash == 1)
	{
		arr[0] = '\0';
		i = 1;
		j = 0;
		while (str[j] != '\0')
			arr[i++] = str[j++];
	}
	else if (options->dash == 0)
	{
		i = 0;
		j = 0;
		while (str[j] != '\0')
			arr[i++] = str[j++];
		arr[i] = '\0';
	}
	return (arr);
}

void	free_and_null_content(char **content)
{
	free (*content);
	*content = NULL;
}
