/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:57:48 by ltalitha          #+#    #+#             */
/*   Updated: 2019/09/24 21:07:16 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	get_next_line(const int fd, char **line);

void	f1(int j)
{
	j = 110;
	return (j);
}

void	f2(int *i) // i - адрес в памяти
{
	i = i * 2;
}

int	main(void)
{
	int i;
	char *line;

	get_next_line(4, line);
	i = 5;
	i = f1(i);
	f2(&i); //берём адрес i
	printf("%d\n", i);
}


