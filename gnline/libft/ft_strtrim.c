/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:17:51 by ltalitha          #+#    #+#             */
/*   Updated: 2019/09/18 21:02:54 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_spec(char const *s)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] == 32 || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[i])
	{
		i++;
		len++;
	}
	if (len)
	{
		while (s[i - 1] == 32 || s[i - 1] == '\n' || s[i - 1] == '\t')
		{
			i--;
			len--;
		}
	}
	return (len);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*news;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	len = ft_strlen_spec(s);
	if (!(news = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[i] == 32 || s[i] == '\n' || s[i] == '\t')
		i++;
	while (j < len)
	{
		news[j] = s[i + j];
		j++;
	}
	news[j] = '\0';
	return (news);
}
