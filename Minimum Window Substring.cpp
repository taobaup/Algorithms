//Minimum Window Substring
class Solution {
public:
	string minWindow(string s, string t) {
		vector<int> a(127);
		int start = 0, len = s.size() + 1, num = 0;

		for (auto i : t)
			--a[i];

		for (int i = 0; i < 127; ++i)
		{
			if (a[i] == 0)
				a[i] = s.size();
			else
				++num;
		}

		for (int i = 0, j = 0; i < s.size(); ++i)
		{
			while (j < s.size() && num)
			{
				if (++a[s[j]] == 0)
					--num;
				++j;
			}

			if (num > 0)
				break;

			if (j - i < len)
			{
				len = j - i;
				start = i;
			}

			if (a[s[i]] == 0)
				++num;

			--a[s[i]];
		}

		return len > s.size() ? "" : s.substr(start, len);
	}
};
