#pragma once

typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node *next;
	struct Node *prior;
}DLNode;

void ListInitiate(DLNode **head);

int ListInsert(DLNode *head, int pos, DataType x);

int ListDelete(DLNode *head, int pos, DataType *x);

int ListLength(DLNode *head);

void ListDestroy(DLNode **head);

int ListGet(DLNode *head, int pos, DataType *x);