#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <unistd.h> // read
#include <fcntl.h> // open
#include <stdio.h> // printf
#include <stdlib.h>
#include "libft/libft.h"
# define BUFFER_SIZE 50

int get_next_line(const int fd, char **line);

#endif