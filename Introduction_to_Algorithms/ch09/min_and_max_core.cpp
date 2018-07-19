#include <iostream>

 using namespace std;

 struct node
 {
	 int max;
	 int min;
};

 node return_node(int a, int b)
 {
	 node res;
	
	 if (a < b)
	 {
		 res.min = a;
		 res.max = b;
	 }
	 else
	 {
		 res.min = b;
		 res.max = a;
	 }

	 return res;
 }

 node min_and_max(int A[], int len)
 {
	 node res, temp;

	 res = return_node(A[0], A[1]);
	 if (len % 2 == 0)
	 {
		 // i+=2 一定不能写成 ++i
		 for (int i = 2; i < len; i+=2)
		 {
			 temp = return_node(A[i], A[i + 1]);
			 if (temp.max > res.max)
				 res.max = temp.max;
				 
			 if (temp.min < res.min)
				 res.min = temp.min;
		 }
	 }
	 else
	 {
		 for (int i = 2; i < len - 1; ++i)
		 {
			 temp = return_node(A[i], A[i + 1]);
			 if (temp.max > res.max)
				 res.max = temp.max;
			 if (temp.min < res.min)
				 res.min = temp.min;
		 }

		 if (A[len - 1] > res.max)
			 res.max = A[len - 1];
		 else if (A[len - 1] < res.min)
			 res.min = A[len - 1];
	 }

	 return res;
 }
 
 int main()
 {
	 int A[] = { 10,-2,300,-30 };
	 int len = sizeof(A) / sizeof(A[0]);
	 if (len < 2)
		 cout << "< 2" << endl;

	 node res = min_and_max(A, len);
	 cout << "min: " << res.min << endl;
	 cout << "max: " << res.max << endl;

	 return 0;
 }
