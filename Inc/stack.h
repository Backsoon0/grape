#ifndef __STACK_H__
#define __STACK_H__

#include "config.h"

void stack_init(stack* this);
void stack_push(stack* this,int number);
int stack_pop(stack* this);
bool stack_isEmpty(stack* this);
int stack_count(stack* this);
void stack_test(void);

#endif