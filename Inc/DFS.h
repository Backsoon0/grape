#ifndef __DFS_H__
#define __DFS_H__

#include <stdbool.h>
#include "config.h"
#include "grape.h"
#include "digrape.h"

void DFS(Dfs* this,Grape* gra, int s);
bool DFS_marked(Dfs* this,int s);
void DFS_pathTo(Dfs* this,int v);
void SreachCycle(Dfs* this,Grape* gra);
bool hasCycle(Dfs* this);
void DFS_free(Dfs* this);
void dfsTest(void);
void DirectedDfsTest(void);
void CycleTest(void);

#endif