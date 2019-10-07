/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:55:58 by ltalitha          #+#    #+#             */
/*   Updated: 2019/09/18 20:44:18 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstiter(t_list *lst, void (*f)(t_list*elem))
{
	t_list	*place;

	place = lst;
	if (lst != NULL || f != NULL)
	{
		while (place)
		{
			(*f)(place);
			place = place->next;
		}
	}
}
