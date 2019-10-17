/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:06:25 by ltalitha          #+#    #+#             */
/*   Updated: 2019/10/17 18:30:40 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
#include <fcntl.h>

int		main(int ac, char **av)
{
	int fd;
	char *line;

	if (ac < 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line))
		printf("%s", line);
	return (0);
}



