#ifndef __DIGRAPE_H__
#define __DIGRAPE_H__

#include "config.h"

// 这些函数用于有向图

void digrape_CreatScan(Grape* gra, int v,int e);
void digrape_CreatArr(Grape* gra, int v,int e,int arr[]);
void printDigrape(Grape* gra);
void digrapetest(void);


#endif