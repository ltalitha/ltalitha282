/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:45:57 by ltalitha          #+#    #+#             */
/*   Updated: 2019/09/09 17:43:29 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int (*f)(char*))
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (tab[i])
	{
		if ((*f)(tab[i]) == 1)
			nb++;
		i++;
	}
	return (nb);
}