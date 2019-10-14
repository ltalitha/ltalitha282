/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 23:27:49 by ltalitha          #+#    #+#             */
/*   Updated: 2019/10/14 20:07:31 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_arr		*ft_newlist(const int fd)
{
	t_arr	*new;

	if (!(new = (t_arr *)malloc(sizeof(t_arr))))
		return (NULL);
	new->fd = fd;
	new->rest = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	return (new);
}

char		*restcheck(char **line, char *rest)
{
	char *p_n;

	if ((*line = ft_strchr(rest, '\n')) != NULL)
	{
		p_n = ft_strsub(rest, 0, *line - rest);
		ft_strcpy(rest, ++(*line));
	}
	else
	{
		p_n = ft_strnew(ft_strlen(rest) + 1);
		ft_strcat(p_n, rest);
		ft_strclr(rest);
	}
	return (p_n);
}

int			get_line(const int fd, char **line, char **rest)
{
	char			buf[BUFF_SIZE + 1];
	char			*p_n;
	char			*tmp;
	int				wr;

	p_n = NULL;
	*line = restcheck(&p_n, *rest);
	while (p_n == 0 && ((wr = read(fd, buf, BUFF_SIZE)) != 0))
	{
		buf[wr] = '\0';
		if ((p_n = ft_strchr(buf, '\n')) != NULL)
		{
			ft_strcpy(*rest, ++p_n);
			ft_strclr(--p_n);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buf)) || wr < 0)
			return (-1);
		free(tmp);
	}
	return ((ft_strlen(*line) || ft_strlen(*rest) || wr) ? 1 : 0);
}

int			get_next_line(const int fd, char **line)
{
	static t_arr	*list;
	t_arr			*tmp;
	int				ret;

	if (fd < 0 || line == 0)
		return (-1);
	if (!list)
		list = ft_newlist(fd);
	tmp = list;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = ft_newlist(fd);
		tmp = tmp->next;
	}
	ret = get_line(fd, line, &tmp->rest);
	return (ret);
}
