/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:20:22 by lsalmi            #+#    #+#             */
/*   Updated: 2022/01/07 16:25:55 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	create_line(char **saved, char **line)
{
	int		len;
	char	*temp;

	len = 0;
	temp = NULL;
	while ((*saved)[len] != '\n' && (*saved)[len] != '\0')
		len++;
	*line = ft_strsub(*saved, 0, len);
	if (*line == NULL)
		return (-1);
	if ((*saved)[len] == '\0')
	{
		ft_strdel(saved);
		return (1);
	}
	temp = ft_strdup(&((*saved)[len + 1]));
	if (temp == NULL)
		return (-1);
	free(*saved);
	*saved = temp;
	if ((*saved)[0] == '\0')
		ft_strdel(saved);
	return (1);
}

static int	decide_output(char **saved, char **line, int ret, const int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && saved[fd] == NULL)
		return (0);
	else
		return (create_line(&(saved[fd]), line));
}

static char	*ft_string_is_null(const char *s1, const char *s2)
{	
	char	*new;

	if (s1 == NULL)
	{
		new = ft_strdup(s2);
		if (new == NULL)
			return (NULL);
	}
	else
	{
		new = ft_strdup(s1);
		if (new == NULL)
			return (NULL);
	}
	return (new);
}

static char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*new;
	size_t	len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL || s2 == NULL)
	{
		new = ft_string_is_null(s1, s2);
		if (new == NULL)
			return (NULL);
	}
	else
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		new = (char *) malloc(sizeof(char) * (len + 1));
		if (new == NULL)
			return (NULL);
		ft_strcpy(new, s1);
		ft_strcat(new, s2);
	}
	return (new);
}

int	get_next_line(const int fd, char **line)
{
	static char	*saved[FD_MAX];
	char		buf[BUFF_SIZE + 1];
	int			ret;
	char		*temp;

	if (fd < 0 || fd >= FD_MAX || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	while (1)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret > 0)
		{
			buf[ret] = '\0';
			temp = ft_strjoin_gnl((const char *) saved[fd], (const char *) buf);
			if (temp == NULL)
				return (-1);
			free(saved[fd]);
			saved[fd] = temp;
			if ((ft_strchr((const char *) saved[fd], '\n')) != NULL)
				break ;
		}
		else
			break ;
	}
	return (decide_output(saved, line, ret, fd));
}
