#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "DFS.h"
#include "stack.h"

/**
 * @brief 深度优先搜索
 * @param this 自己的Dfs
 * @param s 起点
 * @note 此函数为内部函数，内部实现
*/
static void bfs(Dfs* this,int s)
{
    this->mark[s] = true;   //当前节点设为已标记
    for (Node* i = this->gra->arr[s].head; i != NULL; i=i->next)
    {
        //若这个顶点没有经过则继续执行，否则往回走
        if (this->mark[i->information.number] == false)
        {
            this->edgeTo[i->information.number] = s;    //记录上个顶点
            bfs(this,i->information.number);    //使用递归，对这个节点进行bfs搜索
        }
        
    }
    
}

/**
 * @brief 深度优先搜索
 * @param this 自己的Dfs
 * @param gra 要走的地图
 * @param s 起点
*/
void DFS(Dfs* this,Grape* gra, int s)
{
    this->gra = gra;
    this->s = s;
    this->mark = (bool*)malloc(sizeof(bool) * gra->vertex);
    this->edgeTo = (int*)malloc(sizeof(int) * gra->vertex);
    memset(this->mark,0,sizeof(bool) * gra->vertex);
    memset(this->edgeTo,0,sizeof(int) * gra->vertex);   // 全部初始化为0
    this->edgeTo[s] = s;
    bfs(this,s);
}

/**
 * @brief 查看起点是否与某个点相连
 * @param this 自己
 * @param v 某个点
*/
bool DFS_marked(Dfs* this,int s)
{
    return this->mark[s];
}

/**
 * @brief 查看当前有向图是否存在环
 * @param this 自己
*/
bool hasCycle(Dfs* this)
{
    return this->cycle != NULL;
}

static void Cycle(Dfs* this,int s)
{
    this->onStack[s] = true;    //当前顶点在当前栈中
    this->mark[s] = true;   //当前节点设为已标记
    for (Node* i = this->gra->arr[s].head; i != NULL; i=i->next)
    {
        if (hasCycle(this))
        {
            return ;
        }
        //若这个顶点没有经过则继续执行，否则往回走
        else if (this->mark[i->information.number] == false)
        {
            this->edgeTo[i->information.number] = s;    //记录上个顶点
            Cycle(this,i->information.number);    //使用递归，对这个节点进行bfs搜索
        }
        else if (this->onStack[i->information.number])  //若查找到，则记录这个环的顶点
        {
            this->cycle = (stack* )malloc(sizeof(stack));
            stack_init(this->cycle);
            for (int j = s; j != i->information.number; j = this->edgeTo[j])
            {
                stack_push(this->cycle,j);
            }
            stack_push(this->cycle,i->information.number);
            stack_push(this->cycle,s);
        }
    }
    this->onStack[s] = false;   //当前顶点已离开此栈
}

/**
 * @brief 查找是否存在环，不要当DFS用
 * @param this 自己的Dfs
 * @param gra 要走的地图
 * @param s 起点
 * @note 使用此函数会覆盖之前DFS的东西，请先free掉再调用
*/
void SreachCycle(Dfs* this,Grape* gra)
{
    this->gra = gra;
    this->mark = (bool*)malloc(sizeof(bool) * gra->vertex);
    this->edgeTo = (int*)malloc(sizeof(int) * gra->vertex);
    this->onStack = (bool*)malloc(sizeof(bool) * gra->vertex);
    this->cycle = NULL; // 表示没有环
    memset(this->mark,0,sizeof(bool) * gra->vertex);
    memset(this->edgeTo,0,sizeof(int) * gra->vertex);
    memset(this->onStack,0,sizeof(bool) * gra->vertex); // 全部初始化为0
    for (int i = 0; i < this->gra->vertex; i++) //对每个顶点都要进行查找
    {
        if (this->mark[i] == false)
        {
            Cycle(this,i);
        }
        
    }
     
}

/**
 * @brief 在使用'DFS()'和'SreachCycle()'之后可以使用此函数释放内存
 * @param this 要释放的Dfs结构体
 * @note 一定是要再使用'DFS()'和'SreachCycle()'之后
*/
void DFS_free(Dfs* this)
{
    free(this->mark);
    free(this->edgeTo);
    free(this->onStack);
    free(this->cycle);
}

/**
 * @brief 打印某点到起点的路劲
 * @param this 自己
 * @param v 某个点
*/
void DFS_pathTo(Dfs* this,int v)
{
    // if (!this->mark[v])
    // {
    //     return;
    // }
    // for (int i = v; i != this->s; i = this->edgeTo[i])
    // {
    //     printf("%d ",i);    // 找每个点离顶点更近的那个点
    // }
    // printf("%d",this->s);

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
void dfsTest(void)
{
    Grape arr;
    Dfs this;
    grape_CreatScan(&arr,6,8);
    DFS(&this,&arr,0);
    for (int i = 0; i < arr.vertex; i++)
    {
        printf("%d to %d:",this.s,i);
        DFS_pathTo(&this,i);
        printf("\n");
    }
    
}

/**
 * @brief 有向图DFS测试函数
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
void DirectedDfsTest(void)
{
    Grape arr;
    Dfs this;
    int s;
    digrape_CreatScan(&arr,13,22);
    scanf("%d",&s);
    DFS(&this,&arr,s);
    for (int i = 0; i < arr.vertex; i++)
    {
        if (DFS_marked(&this,i))
        {
            printf("%d ",i);
        }
        
    }
}

void CycleTest(void)
{
    Grape arr;
    Dfs this;
    digrape_CreatScan(&arr,13,22);
    SreachCycle(&this,&arr);
    if (hasCycle(&this))
        for (Node* i = this.cycle->first; i != NULL ; i = i->next)
        {
            printf("%d ",i->information.number);
        }
    
}