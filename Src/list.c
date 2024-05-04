#include<stdio.h>
#include<stdlib.h>
#include"list.h"

/**
 * @brief 添加一个节点
 * @param pList 要增加的链表
 * @param number 链表的值
*/
void add(List *pList,int number)
{
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    p->information.number = number;
    p->next = NULL;
    //判断这个p是不是第一个，如果是，那就将p赋给head，如果不是，将这个p链接之前的p。(此p非彼p)
    if(pList->last)    // 不是第一个
    {
        while (pList->last->next)  //这里判断最后节点的next是否还有值，这里一定要判断或循环，否则就会丢失数据
        {
           pList->last = pList->last->next;
        }
        pList->last->next = p;
    }
    else    //是第一个
    {
        pList->head = p;
        pList->last = p;
    }

    // 另一种实现，在链表头增加
    // Node *old = pList->head;
    // pList->head = p;
    // p->next = old;
}

/**
 * @brief 打印链表
 * @param pList 要打印的链表
*/
void printList(List *pList)
{
    Node *p = pList->head;
    while (p)
    {
        printf("%d ",p->information.number);
        p = p->next;
    }
    printf("\n");
}

/**
 * @brief 删除一个节点
 * @param pList 要删除节点的链表
 * @param number 要删除的节点的number值
*/
void del(List *pList,int number)
{
    Node *q = NULL;
    Node *p = pList->head;
    while (p)
    {
        if (p->information.number == number)
        {
            if (q)  // q不是NULL说明不是头节点
            {
                q->next = p->next;
            }
            else
            {
                pList->head = p->next;  // 如果是头节点则直接让头节点改变
            }
            free(p);
            break;
        }
        q = p;
        p = p->next;
    }
}

/**
 * @brief free掉一个链表
*/
void free_node(List *pList)
{
    Node *p = pList->head;
    Node *q = NULL;
    while (p)
    {
        q=p->next;
        free(p);
        p=q;
    }

}

/**
 * @brief 测试函数
 * @note 测试用例
 *  1 2 3 -1 1
*/
void list_test(void)
{
    List list;
    list.head = NULL;
    list.last = NULL;
    int number;
    do{
        scanf("%d",&number);
        if (number != -1)
        {
            add(&list,number);
        }

    }while (number != -1);

    printList(&list);
    scanf("%d",&number);
    del(&list,number);
    printList(&list);
    free_node(&list);
}