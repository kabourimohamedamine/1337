// #include "header.h"
#include <stdlib.h>
#include <unistd.h>
int ft_atoi(const char *str)
{
    int i = 0;
    int res = 0;
    int sign = 1;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    while (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -sign;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res * sign);
}

void *ft_memset(void *s, int c, size_t n)
{
    unsigned char *p;

    p = (unsigned char *)s;
    while (n > 0)
    {
        *p = (unsigned char)c;
        p++;
        n--;
    }
    return (s);
}

void ft_bzero(void *s, size_t n)
{
    unsigned char *p;

    p = (unsigned char *)s;
    while (n > 0)
    {
        *p = 0;
        p++;
        n--;
    }
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *s;
    unsigned char *d;
    d = (unsigned char *)dest;
    s = (unsigned char *)src;

    while (n > 0)
    {
        *d = *s;
        d++;
        s++;
        n--;
    }
    return (dest);
}

void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
    unsigned char *s;
    unsigned char *d;
    d = (unsigned char *)dest;
    s = (unsigned char *)src;

    while (n > 0 && *s != (unsigned char)c)
    {
        *d = *s;
        d++;
        s++;
        n--;
    }
    return (dest);
}

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *s;
    unsigned char *d;
    unsigned char temp[n];
    size_t i;

    i = 0;
    d = (unsigned char *)dest;
    s = (unsigned char *)src;
    while (i < n)
    {
        temp[i] = s[i];
        i++;
    }
    i = 0;
    while (i < n)
    {
        d[i] = temp[i];
        i++;
    }
    return (dest);
}

void *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char *p;

    p = (unsigned char *)s;
    while (n > 0)
    {
        if (*p == (unsigned char)c)
            return (void *)p;
        p++;
        n--;
    }
    return NULL;
}

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char *s;
    unsigned char *p;

    p = (unsigned char *)s1;
    s = (unsigned char *)s2;

    while (n > 0)
    {
        if (*p != *s)
            return (*p - *s);
        p++;
        s++;
        n--;
    }
    return (0);
}

size_t ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while (str[i])
        i++;
    return i;
}

char *ft_strdup(const char *src)
{
    size_t i;
    char *dest;
    size_t len;

    i = 0;
    len = ft_strlen(src);
    dest = malloc(sizeof(char) * (len + 1));
    if (!dest)
        return NULL;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *ft_strcpy(char *dest, const char *src)
{
    size_t i;

    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *ft_strncpy(char *dest, const char *src, size_t n)
{
    size_t i;

    i = 0;
    while (src[i] && i < n)
    {
        dest[i] = src[i];
        i++;
    }
    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }
    return (dest);
}

char *ft_strcat(char *dest, const char *src)
{
    size_t i;

    i = 0;
    while (dest[i])
        i++;
    while (*src)
    {
        dest[i] = *src;
        i++;
        src++;
    }
    dest[i] = '\0';
    return (dest);
}

char *ft_strncat(char *dest, const char *src, size_t n)
{
    size_t i;
    size_t j;

    j = 0;
    i = 0;
    while (dest[i])
        i++;
    while (src[j] && j < n)
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}

char *ft_strchr(const char *str, int c)
{
    while (*str)
    {
        if (*str == (char)c)
            return ((char *)str);
        str++;
    }
    if ((char)c == '\0')
        return ((char *)str);
    return NULL;
}

char *ft_strrchr(const char *str, int c)
{
    int len;

    len = ft_strlen(str);
    while (len >= 0)
    {
        if (str[len] == (char)c)
            return ((char *)&str[len]);
        len--;
    }
    return NULL;
}

char *ft_strstr(const char *str, const char *to_find)
{
    size_t i;
    size_t j;

    i = 0;
    if (!to_find[0])
        return ((char *)str);
    while (str[i])
    {
        j = 0;
        while ((str[i + j] == to_find[j]) && str[i + j])
        {
            j++;
            if (to_find[j] == '\0')
                return ((char *)&str[i]);
        }
        i++;
    }
    return NULL;
}

char *ft_strnstr(const char *str, const char *to_find, size_t n)
{
    size_t i;
    size_t j;

    i = 0;
    if (!to_find[0])
        return ((char *)str);
    while (str[i] && i < n)
    {
        j = 0;
        while ((str[i + j] == to_find[j]) && str[i + j] && (i + j) < n)
        {
            j++;
            if (to_find[j] == '\0')
                return ((char *)&str[i]);
        }
        i++;
    }
    return NULL;
}

int ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return ((unsigned char)*s1 - (unsigned char)*s2);
}

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    if (n == 0)
        return (0);
    while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int ft_isalpha(int c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}

int ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int ft_isalnum(int c)
{
    if (ft_isalpha(c) || ft_isdigit(c))
        return (1);
    return (0);
}

int ft_isascii(int c)
{
    if (c >= 0 && c <= 127)
        return (1);
    return (0);
}

int ft_isprint(int c)
{
    if (c >= 32 && c <= 126)
        return (1);
    return (0);
}

int ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

int ft_tolower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}
void *ft_memalloc(size_t size)
{
    char *p;
    int i;

    i = 0;
    p = malloc(size);
    if (!p)
        return NULL;
    while (i < size)
    {
        p[i] = 0;
        i++;
    }
    return ((void *)p);
}
void ft_memdel(void **ap)
{
    if (ap && *ap)
        free(*ap);
    *ap = NULL;
}
char *ft_strnew(size_t size)
{
    char *p;
    size_t i;

    i = 0;
    p = malloc(size);
    if (!p)
        return NULL;
    while (i < size)
    {
        p[i] = 0;
        i++;
    }
    return (p);
}
void ft_strdel(char **as)
{
    if (as && *as)
        free(*as);
    *as = NULL;
}
void ft_strclr(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        s[i++] = '\0';
    }
}
void ft_striter(char *s, void (*f)(char *))
{
    int i;

    i = 0;
    if (!s || !f)
        return;
    while (s[i])
    {
        f(&s[i]);
        i++;
    }
}
void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
    unsigned int i;

    i = 0;
    if (!s || !f)
        return;
    while (s[i])
    {
        f(i, &s[i]);
        i++;
    }
}
char *ft_strmap(char const *s, char (*f)(char))
{
    char *p;
    int i;

    i = 0;
    if (!s || !f)
        return NULL;
    p = malloc(sizeof(char) * (ft_strlen(s) + 1));
    if (!p)
        return NULL;
    while (s[i])
    {
        p[i] = f(s[i]);
        i++;
    }
    p[i] = '\0';
    return p;
}
char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *p;
    int i;

    i = 0;
    if (!s || !f)
        return NULL;
    p = malloc(sizeof(char) * (ft_strlen(s) + 1));
    if (!p)
        return NULL;
    while (s[i])
    {
        p[i] = f(i, s[i]);
        i++;
    }
    p[i] = '\0';
    return p;
}
int ft_strequ(char const *s1, char const *s2)
{
    int i;

    i = 0;
    if (!s1 || !s2)
        return 0;
    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return 0;
        i++;
    }
    if (s1[i] == s2[i])
        return 1;
    return 0;
}
int ft_strnequ(char const *s1, char const *s2, size_t n)
{
    size_t i;

    i = 0;
    if (!s1 || !s2)
        return 0;
    while (s1[i] && s2[i] && i < n)
    {
        if (s1[i] != s2[i])
            return 0;
        i++;
    }
    if (s1[i] == s2[i] || i == n)
        return 1;
    return 0;
}
char *ft_strsub(char const *s, unsigned int start, size_t len)
{
    char *p;
    int i;

    i = 0;
    p = malloc(sizeof(char) * (len + 1));
    while (i < len)
    {
        p[i] = s[start];
        start++;
        i++;
    }
    p[i] = '\0';
    return (p);
}
char *ft_strjoin(char const *s1, char const *s2)
{
    char *p;
    int i;

    i = 0;
    p = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!p)
        return (NULL);
    while (*s1)
        p[i++] = *s1++;
    while (*s2)
        p[i++] = *s2++;
    p[i] = '\0';
    return (p);
}
char *ft_strtrim(char const *s)
{
    int i;
    int len;
    char *p;
    int j;

    i = 0;
    j = 0;
    len = ft_strlen(s) - 1;
    while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
        i++;
    while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
        len--;
    p = malloc(sizeof(char) * (len - i + 1));
    if (!p)
        return (NULL);
    while (i <= len)
        p[j++] = s[i++];
    p[j] = '\0';
    return (p);
}
void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putstr(char const *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    write(1, s, i);
}
void ft_putendl(char const *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    write(1, s, i);
    write(1, "\n", 1);
}
void ft_putnbr(int n)
{
    if (n == -2147483648)
    {
        write(1, "-2147483648", 11);
        return;
    }
    if (n < 0)
    {
        n = -n;
        write(1, "-", 1);
    }
    if (n <= 9)
        ft_putchar(n + '0');
    else
        ft_putnbr(n / 10);
    ft_putchar((n % 10) + '0');
}
void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}
void ft_putstr_fd(char const *s, int fd)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    write(fd, s, i);
}
void ft_putendl_fd(char const *s, int fd)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    write(fd, s, i);
    write(fd, "\n", 1);
}
void ft_putnbr_fd(int n, int fd)
{
    if (n == -2147483648)
    {
        write(fd, "-2147483648", 11);
        return;
    }
    if (n < 0)
    {
        n = -n;
        write(fd, "-", 1);
    }
    if (n <= 9)
        ft_putchar_fd(n + '0', fd);
    else
        ft_putnbr_fd(n / 10, fd);
    ft_putchar_fd((n % 10) + '0', fd);
}
char *ft_itoa(int n)
{
    char *a;
    int len = 0;
    int nb = n;
    long d = n;
    while (nb / 10 != 0)
    {
        len++;
        nb = nb / 10;
    }
    if (d < 0)
        len++;
    a = malloc(sizeof(char) * len + 1);
    if (d < 0)
    {
        a[0] = '-';
        d = -d;
    }
    a[len + 1] = '\0';
    while (d != 0)
    {
        a[len] = ((d % 10) + '0');
        d /= 10;
        len--;
    }
    return a;
}
size_t strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
    size_t src_len;
    size_t dst_len;
    size_t i;

    src_len = ft_strlen(src);
    dst_len = ft_strlen(dst);
    i = 0;
    if (dst_len <= dstsize)
        return (dstsize + src_len);
    while (src[i] && i < dstsize)
    {
        dst[dst_len + i] = src[i];
        i++;
    }
    dst[dst_len + i] = '\0';
    return (dst_len + src_len);
}