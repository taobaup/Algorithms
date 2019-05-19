#include "stdafx.h"
#include <vector> 

bool can_hu(char* cards)
{
	return true;
}

// 获取听哪些牌
void get_ting_cards(char* cards, std::vector<int>& tingcards)
{
	for (int i = 1; i <= 34; ++i)
	{
		++cards[i];

		if (can_hu(cards))
		{
			tingcards.push_back(i);
		}

		--cards[i];
	}
}

// 七对
bool hu_7_dui(char* cards)
{
	int sum = 0;
	for (int i = 1; i <= 34; ++i)
	{
		if (cards[i] == 1 || cards[i] == 3)
			return false;

		sum += cards[i];
	}

	return sum == 14;
}

// 碰碰胡(手牌部分)
bool hu_pengpeng(char* cards)
{
	int eye_num = 0;
	for (int i = 1; i <= 34; ++i)
	{
		if (cards[i] == 1 || cards[i] == 4)
			return false;

		if (cards[i] == 2)
			eye_num += 1;
	}

	return eye_num == 1;
}

// 大吊车(只有两张手牌胡)
bool hu_dandiao(char* cards)
{
	int eye_num = 0;
	for (int i = 1; i <= 34; ++i)
	{
		if (cards[i] != 2)
		{
			return false;
		}

		eye_num += 1;
	}

	return eye_num == 1;
}

// 十三幺九
// 一万、九万、一筒、九筒、
// 一条、九条、东南西北中发白各一张，然后其中有一种牌是一对
bool hu_13_1_9(char* cards)
{
	int sum = 0;
	char t[] = {
		1,9,10,18,19,27,28,29,30,
		31,32,33,34
	};

	for (int i = 0; i < sizeof(t); ++i)
	{
		int c = cards[i];
		if (c != 1 && c != 2)
			return false;
		sum = sum + c;
	}

	return sum == 14;
}

// 清一色(手牌)
bool is_qingyishe(char* cards)
{
	int color_num[] = {0,0,0,0};
	for (int i = 0; i < 9; ++i)
	{
		color_num[0] += cards[1 + i];
		color_num[1] += cards[10 + i];
		color_num[2] += cards[19 + i];
		color_num[3] += cards[28 + i];
	}

	int sum = color_num[0] + color_num[1] + color_num[2] + color_num[3];
	if (color_num[0] == sum) return true;
	if (color_num[1] == sum) return true;
	if (color_num[2] == sum) return true;
	if (color_num[3] == sum) return true;

	return false;
}

// 卡张
bool qia(char* cards, char hu_index)
{
	if (hu_index > 28)
		return false;

	if (hu_index == 1 || hu_index == 10 
		 || hu_index == 19)
		return false;
	
	if (hu_index == 9 || hu_index == 18 
		 || hu_index == 27)
		return false;

	if (cards[hu_index + 1] == 0 
		 || cards[hu_index - 1] == 0 )
		return false;

	--cards[hu_index + 1];
	--cards[hu_index - 1];
	bool result = can_hu(cards);
	++cards[hu_index + 1];
	++cards[hu_index - 1];

	return result;
}

// 十三烂，只能是147 258 369其中一组，然后加5张字牌
bool is_13_lan(char* cards)
{
	for (int i = 28; i <= 34; ++i)
	{
		if (cards[i] != 1)
			return false;
	}

	for (int i = 0; i < 3; ++i)
	{
		int begin = i * 9;
		int sum = 0;
		for (int j = begin + 1; j <= begin + 9; ++j)
		{
			sum += cards[j];
		}

		if (sum != 3)
			return false;

		if (cards[begin + 1] != cards[begin + 4]
			 || cards[begin + 4] != cards[begin + 7])
			return false;

		if (cards[begin + 2] != cards[begin + 5]
			 || cards[begin + 5] != cards[begin + 8])
			return false;

		if (cards[begin + 3] != cards[begin + 6]
			 || cards[begin + 6] != cards[begin + 9])
			return false;
	}

	return true;
}

// 13烂，隔2张牌以上就行
bool is_13_lan2(char* cards)
{
	for (int i = 28; i <= 34; ++i)
	{
		if (cards[i] != 1)
			return false;
	}

	for (int i = 0; i < 3; ++i)
	{
		int begin = i * 9;
		int sum = 0;
		int last = -1;

		for (int j = begin + 1; j <= begin + 9; ++j)
		{
			sum += cards[j];

			if (cards[j] > 0)
			{
				if (last > 0 && j - last < 3)
					return false;

				last = j;
			}
		}

		if (sum != 3)
			return false;
	}

	return true;
}
