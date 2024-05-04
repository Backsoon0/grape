#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "config.h"

void queue_init(queue* this);
void queue_enqueueNum(queue* this,int number);
void queue_enqueueEdge(queue* this,edge the_edge);
template queue_dequeue(queue* this);
bool queue_isEmpty(queue* this);
int queue_count(queue* this);
void queue_test(void);


#endif