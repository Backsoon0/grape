#ifndef __NODE_H_
#define __NODE_H_

#include "config.h"

void add(List *pList,int number);
void printList(List *pList);
void del(List *pList,int number);
void free_node(List *list);
void list_test(void);

#endif