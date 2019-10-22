/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 21:25:52 by ltalitha          #+#    #+#             */
/*   Updated: 2019/09/04 21:48:53 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int n;

	n = 0;
	while (1)
	{
		if (str[n] == '\0')
		{
			return (n);
		}
		n++;
	}
}