#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "DFO.h"
#include "queue.h"
#include "stack.h"
#include "digrape.h"
#include "DFS.h"

/**
 * @brief 深度优先搜索
 * @param this 自己的Dfs
 * @param s 起点
 * @note 此函数为内部函数，内部实现
*/
static void bfs(Dfo* this,int s)
{
    queue_enqueueNum(this->pro,s);
    this->mark[s] = true;   //当前节点设为已标记
    for (Node* i = this->gra->arr[s].head; i != NULL; i=i->next)
    {
        //若这个顶点没有经过则继续执行，否则往回走
        if (this->mark[i->information.number] == false)
        {
            bfs(this,i->information.number);    //使用递归，对这个节点进行bfs搜索
        }
        
    }
    queue_enqueueNum(this->post,s);
    stack_push(this->reversePost,s);
}

/**
 * @brief 深度优先搜索
 * @param this 自己的Dfs
 * @param gra 要走的地图
 * @param s 起点
 * @note 只支持有向图，不能用于无向图
*/
void DFO(Dfo* this,Grape* gra)
{
    this->gra = gra;
    this->mark = (bool*)malloc(sizeof(bool) * gra->vertex);
    this->pro = (queue*)malloc(sizeof(queue));
    this->post = (queue*)malloc(sizeof(queue));
    this->reversePost = (stack*)malloc(sizeof(stack));
    memset(this->mark,0,sizeof(bool) * gra->vertex);
    queue_init(this->pro);
    queue_init(this->post);
    stack_init(this->reversePost);  //全部进行初始化
    for (int i = 0; i < this->gra->vertex; i++) //每一条边都需要查找
    {
        if (this->mark[i] == false)
        {
            bfs(this,i);
        }
        
    }
}

/**
 * @brief 进行拓扑排序
 * @param this 自己
 * @param gra 图
 * @note 只支持有向图，不能用于无向图
*/
stack* topological(Dfo* this,Grape* gra)
{
    Dfs cycle;
    SreachCycle(&cycle,gra);    // 先查看是否存在环
    if (!hasCycle(&cycle))
    {
        DFO(this,gra);  //如果不存在环在进行拓扑排序
        return this->reversePost;
    }
    else
    {
        printf("存在环");
        return NULL;
    }
    
}

/*
0 5
0 1
0 6
2 0
2 3
3 5
5 4
6 4
8 7
7 6
6 9
9 10
9 11
9 12
11 12
*/
void dfoTest(void)
{
    Dfo this;
    Grape arr;
    digrape_CreatScan(&arr,13,15);
    for (Node* i = topological(&this,&arr)->first; i != NULL; i=i->next)
    {
        printf("%d ",i->information.number);
    }
    
}