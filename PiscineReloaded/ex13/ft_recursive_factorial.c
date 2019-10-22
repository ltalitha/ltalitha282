/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 19:38:46 by ltalitha          #+#    #+#             */
/*   Updated: 2019/09/10 17:58:25 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int i;

	if (nb < 0 || nb > 12)
		return (0);
	if (nb == 0)
		return (1);
	i = 0;
	if (i <= nb)
		i++;
	nb = nb * ft_recursive_factorial(nb - 1);
	return (nb);
}
