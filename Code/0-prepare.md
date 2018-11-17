#### 全排列
>字符串“abc”的全排列：
abc acb bac bca cba cab

* 无重复的全排列
```
#include<iostream>  
#include<assert.h>  

using namespace std;

void Permutation(char *pStr, char *pBegin)
{
	assert(pStr && pBegin);

	if (*pBegin == '\0')
	{
		printf("%s\n", pStr);
	}
	else
	{
		for (char* pCh = pBegin; *pCh != '\0'; ++pCh)
		{
			swap(*pBegin, *pCh);
			Permutation(pStr, pBegin + 1);
			swap(*pBegin, *pCh);
		}
	}
}

int main(void)
{
	char str[] = "abc";
	Permutation(str, str);

	return 0;
}
```
