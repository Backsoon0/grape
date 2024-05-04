#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <stdbool.h>

#define forange( x , y) \
    for(Node* x = y; x != NULL; x=x->next)

// 此头文件包含所有的结构体，需要结构体在这里写并调用

typedef enum _set{
    NUMBER, // 表示使用int类型
    EDGE    // 表示使用edge加权边类型
} set;

// 加权边
typedef struct _edge
{
    int v;  // 其中一个顶点
    int w;  // 另一个顶点
    double weight;  // 权重
} edge;

typedef union _template
{
    int number;
    edge tedge;
} template;

/**
 * @brief 链表、队列、栈的数据结构所需要的节点node
*/
typedef struct node
{
    template information;
    struct node *next;
} Node;

// 优先队列
typedef struct _pq
{
    template* information;
    set type;
    int count;
    int size;
} pq;

/**
 * @brief 链表的数据结构
*/
typedef struct _list
{
    Node *head;
    Node *last;
} List;

/**
 * @brief 队列的数据结构
*/
typedef struct _queue
{
    int count;
    Node* first;
    Node* end;
} queue;

/**
 * @brief stack的数据结构
*/
typedef struct _stack
{
    int count;  // 计数器，记录stack的数量
    Node *first;
} stack;

/**
 * @brief 无向图和有向图的数据结构
*/
typedef struct grape
{
    int vertex; //顶点数量
    int edge;   //边数量

    /**
     * 邻接组
     * 当此结构体表示无向图时，两个顶点的邻接表都要增加另一个顶点
     * 当此结构体表示有向图时，邻接组存放的是当前顶点指向的顶点，比如w->v,那么arr[w]里会有v，但是arr[v]没有w
    */
    List *arr;  
} Grape;

/**
 * @brief 深度优先搜索的算法的结构体
*/
typedef struct DFS
{
    Grape* gra;      //图
    bool *mark;     //起点是否与某点相连，若相连，则mark[i] = true。
    int *edgeTo;    //到某点的路径，"从起点到一个顶点的已知路径的最后一个顶点"
    bool *onStack;  // 用于有向图查找环，查看顶点是否在当前栈中
    stack *cycle;    // 用于记录是哪几个点所组成的环
    int s;  //起点
} Dfs;

/**
 * @brief 广度优先搜索的算法的结构体
*/
typedef struct BFS
{
    Grape* gra;      //图
    bool *mark;     //起点是否与某点相连，若相连，则mark[i] = true。
    int *edgeTo;    //到某点的路径，"从起点到一个顶点的已知路径的最后一个顶点"
    int s;  //起点
} Bfs;

typedef struct DFO
{
    Grape* gra;      //图
    bool *mark;     //起点是否与某点相连，若相连，则mark[i] = true。
    queue *pro;     //递归开始调用的顺序
    queue *post;    //结束递归调用的顺序
    stack *reversePost; //逆后序,也是拓扑排序的顺序
} Dfo;

// 加权边的节点
typedef struct _edgeNode
{
    edge tedge;
    struct _edgeNode* next;
} edgeNode;

// 用于加权边的背包，其实就是一个链表
typedef struct _bag
{
    int count;
    edgeNode* first;
    edgeNode* end;
} bag;

// 加权图
typedef struct _weightgrape
{
    int vertexSize; //顶点数量
    int edgeSize;   //边数量
    bag* edge;  //bag数组
} Weightgrape;

typedef struct _mst
{
    bool *marked;   // marked[v] = true 表示v已经在最小生成树当中
    queue mst;  // 最小生成数所构成的边
    pq crossEdge;   // 横切边的优先队列
} Mst;


#endif