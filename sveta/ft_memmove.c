/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:15:47 by ltalitha          #+#    #+#             */
/*   Updated: 2019/09/17 20:45:20 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	int			i;
	const char	*source;
	char		*dest;

	source = src;
	dest = dst;
	if (dst > src)
	{
		i = len;
		while (i > 0)
		{
			dest[i - 1] = source[i - 1];
			i--;
		}
	}
	else if (dst < src)
		ft_memcpy(dst, src, len);
	return (dest);
}
