
```
#include <iostream>
#include <stdlib.h>

using namespace std;

#define Max_X 2
#define Max_Y 3

int main()
{
	int mapdata[Max_X][Max_Y] = 
	{
		{0,1,2},
		{3,4,5}
	};
	
	int **p = (int **)malloc(Max_X * sizeof(int *));
	if (p == NULL)
	{
		cout << "malloc failed!\n" << endl;
		return -1;
	}
	
	for (int i = 0; i < Max_X; i++)
	{
		p[i] = (int *)malloc(Max_Y * sizeof(int));
		if (p[i] == NULL)
		{
			cout << "malloc failed!\n" << endl;
			return -1;
		}
	}

	for (int i = 0; i < Max_X; ++i)
	{
		for (int j = 0; j < Max_Y; ++j)
		{
			p[i][j] = mapdata[i][j];
		}
	}

	for (int i = 0; i < Max_X; ++i)
	{
		for (int j = 0; j < Max_Y; ++j)
		{
			cout << p[i][j] << endl;
		}
	}
	
	for (int i = 0; i < Max_X; i++)
	{
		if (p[i] != NULL)
		{
			free(p[i]);
			p[i] = NULL;
		}
	}
	
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
	
	return 0;
}
```
