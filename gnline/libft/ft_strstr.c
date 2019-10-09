/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:50:39 by ltalitha          #+#    #+#             */
/*   Updated: 2019/09/18 02:52:51 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int	i;
	char			*res;

	i = 0;
	if (needle == 0 && ft_strlen(needle) == 0)
		return ((char *)haystack);
	if (needle == 0 || ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (i < ft_strlen(haystack))
	{
		if (ft_strncmp((char *)&haystack[i], needle, ft_strlen(needle)) == 0)
			return ((res = (char *)&haystack[i]));
		i++;
	}
	return (NULL);
}
