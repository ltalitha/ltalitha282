/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:57:48 by ltalitha          #+#    #+#             */
/*   Updated: 2019/10/07 17:50:28 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*what_is_in_remain(char *remain, char **line)
{
	char			*sigh_of_new_string;

	sigh_of_new_string = NULL;
	if (remain)
		if ((sigh_of_new_string = ft_strchr(remain, '\n')))
		{
			*sigh_of_new_string = '\0';
			*line = ft_strdup(remain);
			ft_strcpy(remain, ++sigh_of_new_string);
		}
		else
		{
			*line = ft_strdup(remain);
			ft_strclr(remain);
		}
	else
		*line = ft_strnew(0);
	return (sigh_of_new_string);
}

int					get_next_line(const int fd, char **line)
{
	static char		*remain;
	char			buffer[BUFF_SIZE + 1];
	char			*sign_of_new_string;
	char			*tmp;
	int				what_read;

	if (fd < 0 || !line || read(fd, buffer, 0) < 0)
		return (-1);
	sign_of_new_string = what_is_in_remain(remain, line);
	while (!sign_of_new_string && (what_read = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[what_read] = '\0';
		if ((sign_of_new_string = ft_strchr(buffer, '\n')))
		{
			*sign_of_new_string = '\0';
			sign_of_new_string++;
			remain = ft_strdup(sign_of_new_string);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buffer);
		free(tmp);
	}
	return ((what_read || ft_strlen(*line)) ? 1 : 0);
}
