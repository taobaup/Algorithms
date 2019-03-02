#include "SeqList.h"
#include <stdio.h>

int main()
{
	SeqList myList;

	ListInitiate(&myList);
	for (int i = 0; i < 10; ++i)
	{
		ListInsert(&myList, i, i + 1);
	}

	ListPrint(myList);

	DataType x;
	ListDelete(&myList, 0, &x);

	ListPrint(myList);

	// StudentType x[3] =
	// {
	// 	{ 2000001, "张三", "男", 20 },
	// 	{ 2000002, "李四", "男", 21 },
	// 	{ 2000003, "王五", "女", 22 },
	// };

	// ListInitiate(&myList);
	// for (int i = 0; i < 3; ++i)
	// {
	// 	ListInsert(&myList, i, x[i]);
	// }

	// int len = ListLength(myList);
	// for (int i = 0; i < len; ++i)
	// {
	// 	StudentType s;
	// 	ListGet(myList, i, &s);
	// 	printf("%ld %s %s %d\n", s.number, s.name, s.sex, s.age);
	// }

	// add
	printf("\n\n");
	SeqList myList2;

	ListInitiate(&myList2);
	for (int i = 0; i < 10; ++i)
	{
		ListInsert(&myList2, i, i + 1);
	}

	ListInsert(&myList2, 10, 10);

	ListPrint(myList2);

	int res = ListDataDelete(&myList2, 4);
	if (res == 1)
	{
		printf("成功删除掉一个4\n");
	}

	res = ListMoreDataDelete(&myList2, 10);
	if (res == 1)
	{
		printf("成功删除掉10\n");
	}

	res =  ListFind(myList2, 10);
	printf("找到10的位置: %d\n", res);

	res = ListOrderInsert(&myList2, 1);
	if (res == 1)
	{
		printf("按顺序插入1\n");
	}
	
	ListPrint(myList2);
	ListConverse(&myList2);
	ListPrint(myList2);

	return 0;
}
