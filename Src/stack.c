#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "stack.h"

/**
 * @brief stack初始化
 * @param this 要初始化的stack
*/
void stack_init(stack* this)
{
    this->count = 0;
    this->first = NULL;
}

/**
 * @brief push一个stack
 * @param this stack自己
 * @param number 要push的值
*/
void stack_push(stack* this,int number)
{
    Node* anode = (Node*)malloc(sizeof(Node));
    anode->information.number = number;
    anode->next = this->first;
    this->first = anode;
    this->count++;
}

/**
 * @brief 删除一个最近push的值并返回
 * @param this stack自己
*/
int stack_pop(stack* this)
{
    Node* oldfirst = this->first;
    int number = oldfirst->information.number;
    this->first = this->first->next;
    this->count--;
    free(oldfirst);
    return number;
}

/**
 * @brief 查看是否为空
*/
bool stack_isEmpty(stack* this)
{
    return this->count == 0;
}

int stack_count(stack* this)
{
    return this->count;
}

/**
 * @brief 测试函数
 * @note 测试用例
 *  1 2 3 -1
*/
void stack_test(void)
{
    stack this;
    stack_init(&this);
    int number;
    do{
        scanf("%d",&number);
        if (number != -1)
        {
            stack_push(&this,number);
        }

    }while (number != -1);

    while (!stack_isEmpty(&this))
    {
        printf("%d ",stack_pop(&this));
    }
    
}