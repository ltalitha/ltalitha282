/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:57:48 by ltalitha          #+#    #+#             */
/*   Updated: 2019/10/11 18:42:13 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_arr		*newlist(const int fd)
{
	t_arr	*new;

	if (!(new = (t_arr *)malloc(sizeof(t_arr))))
		return (NULL);
	new->fd = fd;
	new->rest = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	return (new);
}

char		*restcheck(char *rest, char **line)
{
	char *p_n;

	if (rest)
	    if ((p_n = ft_strchr(rest, '\n')))
	    {
		    *p_n = '\0';
		    *line = ft_strdup(rest);
		    ft_strcpy(rest, ++p_n);
	    }
	    else
	    {
		*line = ft_strdup(rest);
		ft_strclr(rest);
        }
    else
        *line = ft_strnew(1);
	return (p_n);
}

int			get_line(const int fd, char **line, char **rest)
{
	char			buf[BUFF_SIZE + 1];
	char			*p_n;
	char			*tmp;
	int				wr;

	p_n = NULL;
	p_n = restcheck(*rest, line);
	while (p_n == 0 && ((wr = read(fd, buf, BUFF_SIZE)) != 0))
	{
		buf[wr] = '\0';
		if ((p_n = ft_strchr(buf, '\n')) != NULL)
		{
			*p_n = '\0';
			p_n++;
			*rest = ft_strdup(p_n);
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
		list = newlist(fd);
	tmp = list;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = newlist(fd);
		tmp = tmp->next;
	}
	ret = get_line(fd, line, tmp->rest);
	return (ret);
}
