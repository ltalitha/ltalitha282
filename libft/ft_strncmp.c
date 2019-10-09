/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:48:01 by ltalitha          #+#    #+#             */
/*   Updated: 2019/09/18 04:37:10 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n > ft_strlen(s1))
		n = ft_strlen(s1) + 1;
	if (n > ft_strlen(s2))
		n = ft_strlen(s2) + 1;
	return (ft_memcmp(s1, s2, n));
}
