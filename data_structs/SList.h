#ifndef SLIST_H
#define SLIST_H

#include <stdlib.h>

struct list;
typedef struct list {
    char *item;         /* data item */
    struct list *next;      /* point to successor */
} list;


list *search_list(list *l, char *x);
void insert_list(list **l, char *x);
list *predecessor_list(list *l, char *x);
void delete_list(list **l, char *x);

#endif
