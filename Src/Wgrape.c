#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include "Wgrape.h"

/**
 * @brief 初始化队列
 * @param this 队列自己
*/
void bag_init(bag* this)
{
    this->count = 0;
    this->first = NULL;
    this->end = NULL;
}

/**
 * @brief 向背包添加一个值
 * @param this 要添加的队列
 * @param v 其中一个点
 * @param w 另一个点
 * @param weight 这条边的权重
*/
void bag_add(bag* this,int v,int w,double weight)
{
    edgeNode* anode = (edgeNode*)malloc(sizeof(edgeNode));
    anode->tedge.v = v;
    anode->tedge.w = w;
    anode->tedge.weight = weight;
    anode->next = this->first;
    this->first = anode;
    this->count++;
}

/**
 * @brief 查看是否为空
*/
bool bag_isEmpty(bag* this)
{
    return this->count == 0;
}

int bag_count(bag* this)
{
    return this->count;
}

/**
 * @brief 增加一条加权边
 * @param gra 自己
 * @param v 一个点
 * @param w 另一个点
 * @param weight 这条边的权重
*/
static void add_edge(Weightgrape* gra,int v,int w, double weight)
{
    bag_add(&gra->edge[v],v,w,weight);
    bag_add(&gra->edge[w],v,w,weight);
    gra->edgeSize++;
}

/**
 * @brief 返回边的其中一个顶点
 * @param theEdge 一条边
 * @return int 其中一个顶点
*/
int edge_either(edge* theEdge)
{
    return theEdge->v;
}

/**
 * @brief 返回边的另外一个顶点
 * @param theEdge 一条边
 * @return int 其中另外一个顶点
*/
int edge_other(edge* theEdge,int v)
{
    if (v == theEdge->v)
    {
        return theEdge->w;
    }
    else if (v == theEdge->w)
    {
        return theEdge->v;
    }
    else
    {
        return -1;
    }
}

/**
 * @brief 初始化邻接表(直接输入)(有向图)
 * @param v 顶点数量
 * @param e 边的数量
*/
void Wgrape_CreatScan(Weightgrape* gra, int v,int e)
{
    int a,b;
    double c;
    gra->vertexSize = v;
    gra->edgeSize = 0;
    gra->edge = (bag*)malloc(sizeof(bag) * v);  // bag数组
    memset(gra->edge,0,sizeof(bag) * v);    // 将链表都初始化为0
    for (int i = 0; i < e;i++)
    {
        scanf("%d %d %lf",&a,&b,&c);   // 输入一条边的两个顶点
        add_edge(gra,a,b,c);
    }

}

void Wgrape_print(Weightgrape* gra)
{
    for (int i = 0; i < gra->vertexSize; i++)
    {
        printf("%d:",i);
        for (edgeNode* j = gra->edge[i].first; j != NULL; j = j->next)
        {
            printf("%d %d %.2lf\t",j->tedge.v,j->tedge.w,j->tedge.weight);
        }
        printf("\n");
        // Sleep(2000);
        // system("cls");
    }
    
}

/*
4 5 0.35
4 7 0.37
5 7 0.28
0 7 0.16
1 5 0.32
0 4 0.38
2 3 0.17
1 7 0.19
0 2 0.26
1 2 0.36
1 3 0.29
2 7 0.34
6 2 0.40
3 6 0.52
6 0 0.58
6 4 0.93
*/
void Wgrape_Test(void)
{
    Weightgrape this;
    Wgrape_CreatScan(&this,8,16);
    Wgrape_print(&this);
}