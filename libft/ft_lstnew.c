/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:49:40 by ltalitha          #+#    #+#             */
/*   Updated: 2019/09/20 13:57:47 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*str;
	void	*data;
	size_t	size;

	if (!(str = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content != NULL)
	{
		if (!(data = ft_memalloc(content_size)))
		{
			free(str);
			return (NULL);
		}
		size = content_size;
		ft_memcpy(data, content, content_size);
		str->content = data;
		str->content_size = size;
	}
	else
	{
		str->content = NULL;
		str->content_size = 0;
	}
	str->next = NULL;
	return (str);
}
