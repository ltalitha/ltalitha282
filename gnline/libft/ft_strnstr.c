/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:51:01 by ltalitha          #+#    #+#             */
/*   Updated: 2019/09/18 19:09:27 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *hstack, const char *needle, size_t len)
{
	size_t i;
	size_t n;

	i = 0;
	n = 0;
	if ((*hstack == '\0' && *needle == '\0') || *needle == '\0')
		return ((char*)hstack);
	while (hstack[i] && i < len)
	{
		n = 0;
		if (hstack[i] == needle[n])
		{
			while (hstack[i] == needle[n] && hstack[i] && i < len)
			{
				if (needle[n + 1] == '\0')
					return ((char*)&hstack[i - n]);
				i++;
				n++;
			}
			i -= n;
		}
		i++;
	}
	return (NULL);
}
