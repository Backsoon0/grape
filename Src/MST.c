#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "config.h"
#include "Wgrape.h"
#include "queue.h"
#include "PQ.h"

/**
 * @brief 查看某个点连接的边
 * @param this 自己
 * @param g 需要参考的无向有权图
 * @param s 需要查看的点
 * @note 如果这条边会使最小二叉树形成环则去除，否则就添加到队列中
*/
void mst_visit(Mst* this,Weightgrape* g,int s)
{
    this->marked[s] = true;
    for (edgeNode* i = g->edge[s].first; i != NULL; i = i->next)
    {
        if (!this->marked[edge_other(&i->tedge,s)]) // 添加所有连接s且另一个顶点未被标记的边
        {
            pq_insertEdge(&this->crossEdge,i->tedge);
        }
        
    }
    
}

/**
 * @brief 生成最小二叉树
 * @param this 自己
 * @param g 需要参考的无向有权图
*/
void mst(Mst* this,Weightgrape* g)
{
    // 首先对结构体进行初始化
    queue_init(&this->mst);
    pq_init(&this->crossEdge,g->edgeSize,EDGE);
    this->marked = (bool*)malloc(sizeof(bool) * g->vertexSize);
    memset(this->marked,0,sizeof(bool)*g->vertexSize);
    
    // 首先加入第一个顶点
    mst_visit(this,g,0);
    while (!pq_isEmpty(&this->crossEdge))
    {
        template e = pq_del(&this->crossEdge);  // 获取一条最小的横切边
        int ver1 = e.tedge.v;
        int ver2 = e.tedge.w;
        if (this->marked[ver1] && this->marked[ver2])   // 这条边的两个顶点都被标记说明已失效
            continue;
        queue_enqueueEdge(&this->mst,e.tedge);    // 如果没有则加入队列表示为最小生成树
        // 通过这条边来加入未被标记的顶点，以及它的有效边
        if (!this->marked[ver1])
            mst_visit(this,g,ver1); // 将连接这个点的边添加到优先队列中
        else if (!this->marked[ver2])
            mst_visit(this,g,ver2);
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
void mst_Test(void)
{
    Mst this;
    Weightgrape g;
    Wgrape_CreatScan(&g,8,16);
    mst(&this,&g);
    printf("\n");
    while (!queue_isEmpty(&this.mst))
    {
        template i = queue_dequeue(&this.mst);
        printf("%d %d %lf\n", i.tedge.v, i.tedge.w, i.tedge.weight);
    }
    
}