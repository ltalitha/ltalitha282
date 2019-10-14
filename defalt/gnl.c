/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 20:41:34 by ltalitha          #+#    #+#             */
/*   Updated: 2019/10/14 20:53:46 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_arr		*ft_newlist(const int fd)
{
	t_arr	*new;

	if (!(new = (t_arr *)malloc(sizeof(t_arr))))
		return (NULL);
	new->fd = fd;//записываем в новую ячейку fd
	new->rest = ft_strnew(BUFF_SIZE);//записываем остаток и создаём буфер
	new->next = NULL;//создаём последнюю ячейку NULL
	return (new);
}

char		*restcheck(char **line, char *rest)
{
	char *p_n;

	if ((*line = ft_strchr(rest, '\n')) != NULL)
	{
		p_n = ft_strsub(rest, 0, *line - rest);//помещаем в p_n строку без остатка
		ft_strcpy(rest, ++(*line));//копируем в rest остакток без прочитанной линии
	}
	else
	{
		p_n = ft_strnew(ft_strlen(rest) + 1);//если это последняя строка и остаток NULL создаём новую с остатком и +1 для '\0'
		ft_strcat(p_n, rest);//соединяет p_n с rest
		ft_strclr(rest);//очищаем остаток
	}
	return (p_n);//возвращает строку 
}

int			get_line(const int fd, char **line, char **rest)
{
	char			buf[BUFF_SIZE + 1];//+ 1 под "\0"
	char			*p_n;
	char			*tmp;
	int			wr;//количество бит в буфере

	p_n = NULL;
	*line = restcheck(&p_n, *rest);//записываем в line остаток
	while (p_n == 0 && ((wr = read(fd, buf, BUFF_SIZE)) != 0))//p_n для '\n'
	{
		buf[wr] = '\0';
		if ((p_n = ft_strchr(buf, '\n')) != NULL)//выставление в конце строки '\n'
		{
			ft_strcpy(*rest, ++p_n);//копирует в rest всё после '\n'
			ft_strclr(--p_n);//очищает всё что перед p_n
		}
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buf)) || wr < 0)//склеиваем линию с тем что уже есть
			return (-1);//если не склеилась или wr < 0 ret -1
		free(tmp);
	}
	return ((ft_strlen(*line) || ft_strlen(*rest) || wr) ? 1 : 0);//если что-то в параметрах осталось возвращаем 1, если нет 0
}

int			get_next_line(const int fd, char **line)
{
	static t_arr	*list;
	t_arr		*tmp;
	int		ret;

	if (fd < 0 || line == 0)//проверка на корректность
		return (-1);
	if (!list)//листы для бонуса
		list = ft_newlist(fd);//создание нового листа
	tmp = list;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)//создание новой ячейки
			tmp->next = ft_newlist(fd);//запись в новую ячейку fd
		tmp = tmp->next;//создание указателя
	}
	ret = get_line(fd, line, &tmp->rest);//вызов gl с этими параметрами
	return (ret);
}
