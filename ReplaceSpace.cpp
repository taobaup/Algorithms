题目：替换空格

题意：请实现一个函数，将一个字符串中的空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

解题思路：
计算原字符串长度和空格长度，得到新字符串长度
判断是否越界，若不越界，从后往前复制，遇到空格替换成“%20”
之所以从后往前复制是因为从前往后复制需要多次移动字符，从后往前复制可以减少移动的次数

class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == NULL || length < 0)
			return;

		int origin = 0;
		int space = 0;
		for (int i = 0; str[i] != '\0'; ++i)
		{
			++origin;
			if (str[i] == ' ')
				++space;
		}

		int newLength = origin + 2 * space;
		int indexOfOrigin = origin;
		int indexOfNew = newLength;

		if (newLength > length)
			return;

		while (indexOfOrigin >= 0 && indexOfNew > indexOfOrigin)
		{
			if (str[indexOfOrigin] == ' ')
			{
				str[indexOfNew--] = '0';
				str[indexOfNew--] = '2';
				str[indexOfNew--] = '%';
			}
			else
				str[indexOfNew--] = str[indexOfOrigin];
			--indexOfOrigin;
		}

		return;
	}
};
