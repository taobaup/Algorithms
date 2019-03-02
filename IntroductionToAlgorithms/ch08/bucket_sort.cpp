#include <iostream>
#include <list>

using namespace std;

struct Node
{
	double value;
	Node *next;
};

void bucket_sort(double A[], int len)
{
	Node bucket[10];
	int num = 0;
	
	Node *p = NULL;
	Node *q = NULL;

	int count = 0;
	for (int i = 0; i < 10; ++i)
	{
		bucket[i].value = 0;
		bucket[i].next = NULL;
	}

	for (int i = 0; i < len; ++i)
	{
		Node *insert = new Node();
		insert->value = A[i];
		insert->next = NULL;

		num = A[i] * 10;
		if (bucket[num].next == NULL)
		{
			bucket[num].next = insert;
		}
		else
		{
			p = &bucket[num];
			q = bucket[num].next;

			while (q != NULL && A[i] >= q->value)
			{
				q = q->next;
				p = p->next;
			}

			insert->next = q;
			p->next = insert;
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		p = bucket[i].next;
		if (p == NULL)
			continue;

		while (p != NULL)
		{
			A[count++] = p->value;
			p = p->next;
		}
	}
}

int main()
{
	double A[] = { 0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68 };
	bucket_sort(A, 10);

	for (int i = 0; i < 10; i++)
	{
		cout << A[i] << "\t";
	}
	cout << endl;

	return 0;
}
