#pragma once

typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node *next;
}SLNode;

void ListInitiate(SLNode **head);

int ListLength(SLNode *head);

int ListInsert(SLNode *head, int pos, DataType x);

int ListDelete(SLNode *head, int pos, DataType *x);

int ListGet(SLNode *head, int pos, DataType *x);

void ListDestroy(SLNode **head);