#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "digrape.h"
#include "list.h"

/**
 * @brief 增加一条边
 * @param gra 要增加的邻接表
 * @param a 指出去的顶点
 * @param b 被指向的顶点
 * @note arr存放的是被当前顶点指向的顶点
*/
static void add_edge(Grape* gra,int a,int b)
{
    add(&gra->arr[a],b);
    gra->edge++;
}

/**
 * @brief 初始化邻接表(直接输入)(有向图)
 * @param v 顶点数量
 * @param e 边的数量
*/
void digrape_CreatScan(Grape* gra, int v,int e)
{
    int a,b;
    gra->vertex = v;
    gra->arr = (List*)malloc(sizeof(List) * v);
    memset(gra->arr,0,sizeof(List) * v);    // 将链表都初始化为0
    for (int i = 0; i < e;i++)
    {
        scanf("%d %d",&a,&b);   // 输入一条边的两个顶点
        add_edge(gra,a,b);
    }

}

/**
 * @brief 初始化邻接表(通过数组输入)(有向图)
 * @param v 顶点数量
 * @param e 边的数量
*/
void digrape_CreatArr(Grape* gra, int v,int e,int arr[])
{
    int a,b;
    gra->vertex = v;
    gra->edge = e;
    gra->arr = (List*)malloc(sizeof(List) * v);
    memset(gra->arr,0,sizeof(List) * v);    // 将链表都初始化为0
    for (int i = 0; i < e;i+=2)
    {
        add_edge(gra,arr[i],arr[i+1]);
    }

}

/**
 * @brief 打印grape邻接表
 * @param gra 要打印的邻接表
*/
void printDigrape(Grape* gra)
{
    for (int i = 0; i < gra->vertex; i++)
    {
        printf("%d:",i);
        printList(&gra->arr[i]);
    }
    
}

/**
 * @brief grape测试函数
 * @note 测试用例
4 2
2 3
3 2
6 0
0 1
2 0
11 12
12 9
9 10
9 11
8 9
10 12
11 4
4 3
3 5
7 8
8 7
5 4
0 5
6 4
6 9
7 6
*/
void digrapetest(void)
{
    Grape arr;
    digrape_CreatScan(&arr,13,22);
    printDigrape(&arr);
}