/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:07:41 by ltalitha          #+#    #+#             */
/*   Updated: 2019/09/20 14:37:19 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	if (!(new = (char*)ft_memalloc(ft_strlen(s) + 1)))
		return (NULL);
	ft_strcpy(new, s);
	while (new[i])
	{
		new[i] = (*f)(i, new[i]);
		i++;
	}
	return (new);
}
