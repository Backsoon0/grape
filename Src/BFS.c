#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BFS.h"
#include "queue.h"
#include "stack.h"

/**
 * @brief 广度优先搜索
 * @param this 自己的Dfs
 * @param s 起点
 * @note 此函数为内部函数，内部实现
*/
static void bfs(Bfs* this,int s)
{
    this->mark[s] = true;
    queue tqueue;
    queue_init(&tqueue);    // 初始化一个队列，这个队列中的每个点都是要记录它相邻的点，
    queue_enqueueNum(&tqueue,s);
    while (!queue_isEmpty(&tqueue))
    {
        int w = queue_dequeue(&tqueue).number;
        for (Node* i = this->gra->arr[w].head; i != NULL; i = i->next)
        {
            if (!this->mark[i->information.number])
            {
                this->edgeTo[i->information.number] = w;    // 标记这个相邻的点到起点的最后一个点为w
                this->mark[i->information.number] = true;   // 表示这个点已经被标记
                queue_enqueueNum(&tqueue,i->information.number);   // 将新发现的放入队列中，一个个好好排好队，并依次查看它们相邻的点
            }
            
        }
        
    }
    

}

void BFS(Bfs* this,Grape* gra,int s)
{
    this->gra = gra;
    this->s = s;
    this->edgeTo = (int*)malloc(sizeof(int) * this->s);
    this->mark = (bool*)malloc(sizeof(bool) * this->s);
    memset(this->edgeTo,0,sizeof(int) * this->s);
    memset(this->mark,false,sizeof(bool) * this->s);    // 初始化为 0
    this->edgeTo[s] = s;    // 结束停止条件
    bfs(this,s);
}

/**
 * @brief 查看起点是否与某个点相连
 * @param this 自己
 * @param v 某个点
*/
bool BFS_hasPathTo(Bfs* this,int s)
{
    return this->mark[s];
}

/**
 * @brief 打印某点到起点的路劲
 * @param this 自己
 * @param v 某个点
*/
void BFS_pathTo(Bfs* this,int v)
{
    stack tq;
    stack_init(&tq);
    if (!this->mark[v])
    {
        return;
    }
    for (int i = v; i != this->s; i = this->edgeTo[i])
    {
        stack_push(&tq,i);   // 找每个点离顶点更近的那个点
    }
    printf("%d ",this->s);
    while (!stack_isEmpty(&tq))
    {
        printf("%d ",stack_pop(&tq));
    }
    
    // if (!this->mark[v])
    // {
    //     return;
    // }
    // for (int i = v; i != this->s; i = this->edgeTo[i])
    // {
    //     printf("%d ",i);    // 找每个点离顶点更近的那个点
    // }

}

/**
 * @brief dfs测试函数
 * @note 测试用例
0 5
2 4
2 3
1 2
0 1
3 4
3 5
0 2
*/
void bfsTest(void)
{
    Grape arr;
    Bfs this;
    grape_CreatScan(&arr,6,8);
    BFS(&this,&arr,0);
    for (int i = 0; i < arr.vertex; i++)
    {
        printf("%d to %d:",this.s,i);
        BFS_pathTo(&this,i);
        printf("\n");
    }
    
}