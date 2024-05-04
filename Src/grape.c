#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grape.h"
#include "list.h"

/**
 * @brief 增加一条边
 * @param gra 要增加的邻接表
 * @param a 其中一个顶点
 * @param b 另一个顶点
 * @note 两个顶点的邻接表都要增加另一个顶点
*/
static void add_edge(Grape* gra,int a,int b)
{
    add(&gra->arr[a],b);
    add(&gra->arr[b],a);
    gra->edge++;
}

/**
 * @brief 初始化邻接表(直接输入)
 * @param v 顶点数量
 * @param e 边的数量
*/
void grape_CreatScan(Grape* gra, int v,int e)
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
 * @brief 初始化邻接表(通过数组输入)
 * @param v 顶点数量
 * @param e 边的数量
*/
void grape_CreatArr(Grape* gra, int v,int e,int arr[])
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
void printGrape(Grape* gra)
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
0 5
4 3
0 1
9 12
6 4
5 4
0 2
11 12
9 10
0 6
7 8
9 11
5 3
*/
void grapetest(void)
{
    Grape arr;
    grape_CreatScan(&arr,13,13);
    printGrape(&arr);
}