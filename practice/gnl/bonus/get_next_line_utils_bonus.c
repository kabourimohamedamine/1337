#include "get_next_line.h"
int check_new_line(char *str)
{
    if (!str)
        return 0;
    while (*str)
    {
        if (*str == '\n')
            return 1;
        str++;
    }
    return 0;
}

char *ft_store(char *src, char *dst, int size)
{
    int i;
    int j;
    char *a;

    j = 0;
    i = 0;
    a = malloc(ft_strlen(dst) + size + 1);
    if (!a)
        return NULL;
    while (dst && dst[i])
    {
        a[i] = dst[i];
        i++;
    }
    while (j < size)
    {
        a[i + j] = src[j];
        j++;
    }
    a[i + j] = '\0';
    free(dst);
    return (a);
}
int ft_strlen(char *s)
{
    int i;
    if (!s)
        return 0;

    i = 0;
    while (s[i])
        i++;
    return i;
}
char *ft_last_fill(char *src, char *dst)
{
    int i;
    i = 0;
    while (src[i] != '\n')
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\n';
    i++;
    dst[i] = '\0';
    return dst;
}
char *ft_free(char *src)
{
    char *dst;
    int i;
    int j;

    i = 0;
    while (src[i] != '\n')
        i++;
    i++;
    j = 0;
    while (src[i + j])
        j++;
    dst = malloc(j + 1);
    if (!dst)
        return NULL;
    j = 0;
    while (src[i + j])
    {
        dst[j] = src[i + j];
        j++;
    }
    dst[j] = '\0';
    free(src);
    return dst;
}