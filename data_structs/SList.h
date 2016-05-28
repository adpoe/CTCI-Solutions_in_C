#ifndef SLIST_H
#define SLIST_H

#include <stdlib.h>

struct list;
typedef struct list {
    void *item;         /* data item */
    struct list *next;      /* point to successor */
} list;


list *search_list(list *l, void *x);
void insert_list(list **l, void *x);
list *predecessor_list(list *l, void *x);
void delete_list(list **l, void *x);

#endif
