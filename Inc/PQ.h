#ifndef __PQ_H__
#define __PQ_H__

#include "config.h"

enum max_or_min{
    MAX,    // 表示父节点为最大的
    MIN     // 表示父节点为最小的
};

#define TYPE MIN

void pq_init(pq* this,int count,set type);
int pq_count(pq* this);
bool pq_isEmpty(pq* this);
void pq_insertEdge(pq* this,edge e);
void pq_inserNumber(pq*this,int number);
template pq_del(pq* this);
void pqtest(void);


#endif