#pragma once

#define MaxSize 50 
typedef int DataType;

// typedef struct
// {
// 	long number;
// 	char name[10];
// 	char sex[3];
// 	int age;
// }StudentType;
// typedef StudentType DataType;

typedef struct
{
	DataType list[MaxSize];
	int size;
}SeqList;

void ListInitiate(SeqList *L);

int ListLength(SeqList L);

int ListInsert(SeqList *L, int pos, DataType x);

int ListDelete(SeqList *L, int pos, DataType *x);

int ListGet(SeqList L, int pos, DataType *x);

void ListPrint(SeqList L);

// add
int ListDataDelete(SeqList *L, DataType x);

int ListMoreDataDelete(SeqList *L, DataType x);

int ListFind(SeqList L, DataType x);

int ListOrderInsert(SeqList *L, DataType x);

void ListConverse(SeqList *L);