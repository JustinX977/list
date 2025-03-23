#ifndef __KERNEL_LIST_H__
#define __KERNEL_LIST_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include"list.h"

typedef int datatype;

typedef struct node
{
    datatype data;
    struct list_head list;
}node_t;

node_t *list_create(datatype x);
void list_push_front(datatype x);
void list_push_back(datatype x);
void list_pop_front(void);
void list_pop_back(void);
bool list_is_empty(void);
node_t *search_node(datatype x);
void list_erase(void);

void list_print(void);




#endif /*__KERNEL_LIST_H__*/