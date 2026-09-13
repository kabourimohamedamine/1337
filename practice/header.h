#ifndef HEADER_H
#define HEADER_H

typedef unsigned long size_t;

typedef struct s_list
{
    void *content;
    size_t content_size;
    struct s_list *next;
} t_list;

#endif
