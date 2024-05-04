#ifndef __GRAPE_H__
#define __GRAPE_H__

#include "config.h"

// 这些函数用于无向图

void grape_CreatScan(Grape* gra, int v,int e);
void grape_CreatArr(Grape* gra, int v,int e,int arr[]);
void printGrape(Grape* gra);
void grapetest(void);

#endif