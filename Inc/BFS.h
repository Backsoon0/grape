#ifndef __BFS_H__
#define __BFS_H__

#include <stdbool.h>
#include "config.h"
#include "grape.h"

void BFS(Bfs* this,Grape* gra,int s);
bool BFS_hasPathTo(Bfs* this,int s);
void BFS_pathTo(Bfs* this,int v);
void bfsTest(void);

#endif