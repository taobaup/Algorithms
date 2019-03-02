#include "DLinkList.h"
#include <stdio.h>

int main()
{
	DLNode *head;

	ListInitiate(&head);

	for (int i = 0; i < 10; ++i)
	{
		ListInsert(head, i, i + 1);
	}

	DataType x;
	ListDelete(head, 4, &x);

	for (int i = 0; i < ListLength(head); ++i)
	{
		int ret = ListGet(head, i, &x);
		printf("%d\t", x);
	}

	ListDestroy(&head);

	return 0;
}