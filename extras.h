#ifndef _EXTRAS_H_
#define _EXTRAS_H_

#include "base.h"
#include "record.h"

// function prototypes
int defragment(Record[]);
void display_stats(Record[]);
int CompareByID(const void *v1, const void *v2);
int CompareByage(const void *v1, const void *v2);
void sort_userlist(Record records[], int *pcount);
#endif
