/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:10:56 by ltalitha          #+#    #+#             */
/*   Updated: 2019/09/05 19:33:33 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	char			*temp;
	unsigned long	len;
	unsigned long	i;

	len = 0;
	while (src[len] != '\0')
		len++;
	temp = (char*)malloc(len + 1);
	i = len;
	len = 0;
	while (len < i)
	{
		temp[len] = src[len];
		len++;
	}
	temp[len] = '\0';
	return (temp);
}
