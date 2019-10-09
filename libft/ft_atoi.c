/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:23:31 by ltalitha          #+#    #+#             */
/*   Updated: 2019/09/20 19:51:55 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				find_sign(const char *str)
{
	int					i;
	int					sign;

	i = 0;
	sign = 1;
	while (str[i] && !ft_isdigit(str[i]))
	{
		if (str[i] == '-')
			sign = -1;
		else if (str[i] == '+')
			sign = 1;
		i++;
	}
	return (sign);
}

int						ft_atoi(const char *str)
{
	unsigned long long	n;
	unsigned long long	new_n;
	int					i;
	int					sign;

	n = 0;
	i = 0;
	sign = (find_sign(str));
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		new_n = n * 10 + str[i] - 48;
		if (new_n < n)
			return (sign > 0 ? -1 : 0);
		n = new_n;
		i++;
	}
	return (n * sign);
}
