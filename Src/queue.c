#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

/**
 * @brief 初始化队列
 * @param this 队列自己
*/
void queue_init(queue* this)
{
    this->count = 0;
    this->first = NULL;
    this->end = NULL;
}

/**
 * @brief 向队列添加一个值
 * @param this 要添加的队列
 * @param number 要添加的值
 * @note 队列是先进先出的链表，最先添加的值是最先删除的
*/
void queue_enqueueNum(queue* this,int number)
{
    // Node* p = (Node*)malloc(sizeof(Node));
    // p->number = number;
    // p->next = NULL;
    // if (this->first)
    // {
    //     this->end->next = p;
    //     this->end = p;
    // }
    // else
    // {
    //     this->first = p;
    //     this->end = p;
    // }
    Node* oldend = this->end;
    this->end = (Node*)malloc(sizeof(Node));
    this->end->information.number = number;
    this->end->next = NULL;
    if (queue_isEmpty(this))
    {
        this->first = this->end;
    }
    else
    {
        oldend->next = this->end;
    }
    
    this->count++;
}

/**
 * @brief 向队列添加一个有向边
 * @param this 要添加的队列
 * @param the_edge 要添加的有向边
 * @note 队列是先进先出的链表，最先添加的值是最先删除的
*/
void queue_enqueueEdge(queue* this,edge the_edge)
{
    Node* oldend = this->end;
    this->end = (Node*)malloc(sizeof(Node));
    this->end->information.tedge = the_edge;
    this->end->next = NULL;
    if (queue_isEmpty(this))
    {
        this->first = this->end;
    }
    else
    {
        oldend->next = this->end;
    }
    
    this->count++;
}

/**
 * @brief 向队列删除一个值
 * @param this 要删除一个值的队列
 * @note 队列是先进先出的链表，最先添加的值是最先删除的,
 *       以及，返回的是template，需要.number或.tedge
*/
template queue_dequeue(queue* this)
{
    Node* oldfirst = this->first;
    template key = oldfirst->information;
    this->first = this->first->next;
    this->count--;
    free(oldfirst);
    return key;
}

/**
 * @brief 查看是否为空
*/
bool queue_isEmpty(queue* this)
{
    return this->count == 0;
}

int queue_count(queue* this)
{
    return this->count;
}

/**
 * @brief 测试函数
 * @note 测试用例
 *  1 2 3 -1
*/
void queue_test(void)
{
    queue this;
    queue_init(&this);
    int number;
    do{
        scanf("%d",&number);
        if (number != -1)
        {
            queue_enqueueNum(&this,number);
        }

    }while (number != -1);

    while (!queue_isEmpty(&this))
    {
        printf("%d ",queue_dequeue(&this).number);
    }
    
}