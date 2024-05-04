#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "PQ.h"

/**
 * @brief 初始化优先队列
 * @param this 自己
 * @param count 需要数组的大小
 * @param type 需要插入的类型
 *      @arg NUMBER 表示int类型
 *      @arg EDGE 表示edge加权边类型
*/
void pq_init(pq* this,int count,set type)
{
    this->type = type;  // 设定结构类型
    this->information = (template*)malloc(sizeof(template) * (count+1));
    memset(this->information,0,sizeof(template) * (count+1));
    this->count = 0;    // 表示目前优先队列还没有任何东西
    this->size = count; // 表是最大的大小
}

/**
 * @brief 比较数据
 * @param a 其中一个值
 * @param b 另一个值
 * @return information[a] < information[b]则返回true，大于则返回false
*/
static bool compare(pq* this,int a,int b)
{
    if (this->type == NUMBER)
    {
        #if TYPE
            return this->information[a].number < this->information[b].number;
        #else
            return this->information[a].number > this->information[b].number;
        #endif
    }
    else if (this->type == EDGE)
    {
        #if TYPE
            return this->information[a].tedge.weight < this->information[b].tedge.weight;
        #else
            return this->information[a].tedge.weight > this->information[b].tedge.weight;
        #endif
    }
}

/**
 * @brief 交换数据
*/
static void exch(pq* this,int a,int b)
{
    template temp = this->information[a];
    this->information[a] = this->information[b];
    this->information[b] = temp;
}

static void swim(pq* this,int k)
{
    while (k > 1 && compare(this,k/2,k))  // 当这个子节点大于父节点时就替换
    {
        exch(this,k/2,k);
        k /= 2;
    }
    
}

static void sink(pq* this,int k)
{
    while (k*2 <= this->count)    //防止超出界限
    {
        int j = k*2;
        if (compare(this,j,j+1) && j < this->count)   // 找出子节点最大的那一个,如果j是最后一个就直接退出
        {
            j++;
        }
        if (compare(this,j,k)) //比较一下，若子节点都比父节点小，则退出循环
        {
            break;
        }
        exch(this,k,j);
        k = j;
    }
    
}

int pq_count(pq* this)
{
    return this->count;
}

bool pq_isEmpty(pq* this)
{
    return this->count == 0;
}

/**
 * @brief 插入加权边
 * @param this 自己
 * @param e 需要加入的边
*/
void pq_insertEdge(pq* this,edge e)
{
    this->information[++this->count].tedge = e;
    swim(this,this->count);
}

/**
 * @brief 插入一个数字
*/
void pq_inserNumber(pq*this,int number)
{
    this->information[++this->count].number = number;
    swim(this,this->count);
}

/**
 * @brief 删除一个temple
*/
template pq_del(pq* this)
{
    template key = this->information[1];
    exch(this,1,this->count--);
    // 可以在这里搞一个防止游离的东西
    sink(this,1);
    return key;
}

void pqtest(void)
{
    pq this;
    pq_init(&this,10,NUMBER);
    pq_inserNumber(&this,10);
    pq_inserNumber(&this,12);
    pq_inserNumber(&this,13);
    pq_inserNumber(&this,6);
    pq_inserNumber(&this,8);
    while (pq_count(&this) != 0)
    {
        printf("%d ",pq_del(&this).number);
    }
    
}
