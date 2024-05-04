#ifndef __WGRAPE_H__
#define __WGRAPE_H__

#include "config.h"

void Wgrape_CreatScan(Weightgrape* gra, int v,int e);
void Wgrape_print(Weightgrape* gra);
void Wgrape_Test(void);

int edge_either(edge* theEdge);
int edge_other(edge* theEdge,int v);


#endif
