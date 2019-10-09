/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:56:59 by ltalitha          #+#    #+#             */
/*   Updated: 2019/09/18 18:54:41 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *dest;

	dest = (unsigned char *)b;
	while (len != 0)
	{
		*dest = (unsigned char)c;
		if (len != 0)
		{
			dest++;
		}
		len--;
	}
	return (b);
}
