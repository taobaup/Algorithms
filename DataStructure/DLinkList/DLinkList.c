#include "DLinkList.h"
#include <stdio.h>
#include <stdlib.h>

void ListInitiate(DLNode **head)
{
	*head = (DLNode*)malloc(sizeof(DLNode));
	(*head)->prior = *head;
	(*head)->next = *head;
}

int ListInsert(DLNode *head, int pos, DataType x)
{
	DLNode *p = head->next;
	int j = 0;

	while (p != head && j < pos)
	{
		p = p->next;
		++j;
	}

	if (j != pos)
	{
		printf("参数pos不合法111!\n");
		return 0;
	}

	DLNode *s = (DLNode*)malloc(sizeof(DLNode));
	s->data = x;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;

	return 1;
}

int ListDelete(DLNode *head, int pos, DataType *x)
{
	DLNode *p = head->next;

	int j = 0;
	while (p->next != head && j < pos)
	{
		p = p->next;
		++j;
	}

	if (j != pos)
	{
		printf("参数pos不合法222!\n");
		return 0;
	}

	*x = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);

	return 1;
}

int ListLength(DLNode *head)
{
	DLNode *p = head;
	int size = 0;
	while (p->next != head)
	{
		p = p->next;
		++size;
	}

	return size;
}

void ListDestroy(DLNode **head)
{
	int len = ListLength(*head);
	DLNode *p = *head;

	for (int i = 0; i <= len; ++i)
	{
		DLNode *q = p;
		p = p->next;
		free(q);
	}

	*head = NULL;
}

int ListGet(DLNode *head, int pos, DataType *x)
{
	DLNode *p = head->next;
	int j = 0;
	while (p != head && j < pos)
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