#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
int ft_strlen(char *s, int l);
int check_new_line(char *str);
char *ft_store(char *src, char *dst, int size);
char *ft_last_fill(char *src, char *dst);
char *ft_free(char *src);
#endif
