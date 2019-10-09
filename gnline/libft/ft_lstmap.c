/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 03:44:36 by ltalitha          #+#    #+#             */
/*   Updated: 2019/09/18 20:44:55 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*tmpres;
	t_list	*tmplst;

	if (lst == NULL || f == NULL)
		return (NULL);
	tmplst = f(lst);
	if ((res = ft_lstnew(tmplst->content, tmplst->content_size)))
	{
		tmpres = res;
		lst = lst->next;
		while (lst != NULL)
		{
			tmplst = (*f)(lst);
			if (!(tmpres->next = ft_lstnew(tmplst->content,
							tmplst->content_size)))
				return (NULL);
			tmpres = tmpres->next;
			lst = lst->next;
		}
	}
	return (res);
}
