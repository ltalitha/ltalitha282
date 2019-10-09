/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:33:46 by ltalitha          #+#    #+#             */
/*   Updated: 2019/09/18 21:15:26 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	n;
	size_t	len_dest;
	char	*current_dest;
	char	*current_src;

	n = size;
	current_dest = dest;
	current_src = (char*)src;
	while (n-- && *current_dest)
		current_dest++;
	len_dest = current_dest - dest;
	n = size - len_dest;
	if (!(n--))
		return (ft_strlen(src) + len_dest);
	while (*current_src)
	{
		if (n)
		{
			*current_dest++ = *current_src;
			n--;
		}
		current_src++;
	}
	*current_dest = '\0';
	return ((unsigned long)(len_dest + (current_src - src)));
}
