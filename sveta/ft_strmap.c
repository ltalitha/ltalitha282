/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:05:37 by ltalitha          #+#    #+#             */
/*   Updated: 2019/09/18 19:35:26 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*new;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	if (!(new = (char*)malloc(ft_strlen(s) + 1)))
		return (NULL);
	ft_strcpy(new, s);
	while (new[i])
	{
		new[i] = (*f)(new[i]);
		i++;
	}
	return (new);
}
