#include "SeqList.h"
#include <stdio.h>

void ListInitiate(SeqList *L)
{
	L->size = 0;
}

int ListLength(SeqList L)
{
	return L.size;
}

int ListInsert(SeqList *L, int pos, DataType x)
{
	if (L->size >= MaxSize)
	{
		printf("顺序表已满无法插入!\n");
		return 0;
	}
	else if (pos < 0 || pos > L->size)
	{
		printf("参数pos不合法!\n");
		return 0;
	}
	else
	{
		// 不要写成 size()-1
		for (int i = L->size; i > pos; --i)
		{
			L->list[i] = L->list[i - 1];
		}

		L->list[pos] = x;
		++L->size;
		return 1;
	}
}

int ListDelete(SeqList *L, int pos, DataType *x)
{
	if (L->size <= 0)
	{
		printf("顺序表已空无数据元素可删!\n");
		return 0;
	}
	else if (pos < 0 || pos >= L->size)
	{
		printf("参数pos不合法!\n");
		return 0;
	}
	else
	{
		*x = L->list[pos];
		for (int i = pos; i < L->size; ++i)
		{
			L->list[i] = L->list[i + 1];
		}

		--L->size;
		return 1;
	}
}

int ListGet(SeqList L, int pos, DataType *x)
{
	if (pos < 0 || pos >= L.size)
	{
		printf("参数pos不合法!\n");
		return 0;
	}
	else
	{
		*x = L.list[pos];
		return 1;
	}
}

void ListPrint(SeqList L)
{
	for (int i = 0; i < ListLength(L); ++i)
	{
		DataType x;
		ListGet(L, i, &x);
		printf("%d\t", x);
	}

	printf("\n");
}

int ListDataDelete(SeqList *L, DataType x)
{
	int i = 0;
	for (i = 0; i < L->size; ++i)
	{
		if (x == L->list[i])
		{
			break;
		}
	}

	if (i == L->size)
	{
		return 0;
	}
	else
	{
		for (int j = i; j < L->size; ++j)
		{
			L->list[j] = L->list[j + 1];
		}

		--L->size;
		return 1;
	}
}

int ListMoreDataDelete(SeqList *L, DataType x)
{
	int flag = 0;
	int i = 0;
	for (i = 0; i < L->size; ++i)
	{
		if (x == L->list[i])
		{
			for (int j = i; j < L->size; ++j)
			{
				L->list[j] = L->list[j + 1];
			}

			--L->size;
			flag = 1;
			--i;
		}
	}

	return flag;
}

int ListFind(SeqList L, DataType x)
{
	for (int i = 0; i < L.size; ++i)
	{
		if (L.list[i] == x)
		{
			return i;
		}
	}

	return -1;
}

int ListOrderInsert(SeqList *L, DataType x)
{
	if (L->size >= MaxSize - 1)
	{
		printf("顺序表已满无法插入!\n");
		return 0;
	}
	else
	{
		int i = L->size - 1; 
		while (i >= 0)
		{
			if (x < L->list[i])
			{
				--i;
			}
			else
			{
				break;
			}
		}
		
		++i;
		for (int j = L->size - 1; j >= i; --j)
		{
			L->list[j + 1] = L->list[j];
		}

		L->list[i] = x;
		++L->size;
		return 1;
	}
}

void ListConverse(SeqList *L)
{
	const int mid = L->size / 2;
	for (int i = 0; i < mid; ++i)
	{
		DataType tmp = L->list[i];
		L->list[i] = L->list[L->size - 1 - i];
		L->list[L->size - 1 - i] = tmp;
	}
}