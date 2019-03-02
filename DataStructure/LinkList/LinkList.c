#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>

void ListInitiate(SLNode **head)
{
	*head = (SLNode*)malloc(sizeof(SLNode));
	(*head)->next = NULL;
}

int ListLength(SLNode *head)
{
	SLNode *p = head;
	int size = 0;

	while (p->next != NULL)
	{
		++size;
		p = p->next;
	}

	return size;
}

int ListInsert(SLNode *head, int pos, DataType x)
{
	SLNode *p = head;
	int j = -1;
	while (p->next != NULL && j < pos - 1)
	{
		p = p->next;
		++j;
	}

	if (j != pos - 1)
	{
		printf("参数pos不合法");
		return 0;
	}

	SLNode *q = (SLNode*)malloc(sizeof(SLNode));
	q->data = x;
	q->next = p->next;
	p->next = q;

	return 1;
}

int ListDelete(SLNode *head, int pos, DataType *x)
{
	SLNode *p = head;
	int j = -1;

	while (p->next != NULL && p->next->next != NULL &&j < pos - 1)
	{
		p = p->next;
		++j;
	}

	if (j != pos - 1)
	{
		printf("参数pos不合法");
		return 0;
	}

	SLNode *q = p->next;
	*x = q->data;
	p->next = p->next->next;
	free(q);

	return 1;
}

int ListGet(SLNode *head, int pos, DataType *x)
{
	SLNode *p = head;
	int j = -1;
	while (p->next != NULL && j < pos)
	{
		p = p->next;
		++j;
	}

	if (j != pos)
	{
		printf("参数pos不合法");
		return 0;
	}

	*x = p->data;

	return 1;
}

void ListDestroy(SLNode **head)
{
	SLNode *p = *head;
	while (p != NULL)
	{
		SLNode *q = p;
		p = p->next;
		free(q);
	}

	// 不要遗漏这一步
	*head = NULL;
}