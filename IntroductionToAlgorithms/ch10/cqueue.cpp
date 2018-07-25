#include <iostream>
#include <stack>

using namespace std;

template<class T>
class CQueue
{
public:
	CQueue() {}
	~CQueue() {}

	void push_back(const T& node);
	T pop_front();
	T front();
	bool empty() const;

private:
	stack<T> stack1;
	stack<T> stack2;
};

template<class T>
void CQueue<T>::push_back(const T& node)
{
	stack1.push(node);
}

template<class T>
T CQueue<T>::pop_front()
{
	if (stack2.empty())
	{
		while (!stack1.empty())
		{
			int &temp = stack1.top();
			stack1.pop();
			stack2.push(temp);
		}
	}

	T &res = stack2.top();
	stack2.pop();

	return res;
}

template<class T>
T CQueue<T>::front()
{
	if (stack2.empty())
	{
		while (!stack1.empty())
		{
			int &temp = stack1.top();
			stack1.pop();
			stack2.push(temp);
		}
	}

	T res = stack2.top();

	return res;
}

template<class T>
bool CQueue<T>::empty() const
{
	return stack1.empty() ? true : false;
}

int main()
{
	CQueue<int> CQ;
	for (int i = 0; i < 10; ++i)
	{
		CQ.push_back(i);
	}

	cout << "empty: " << CQ.empty() << endl;
	cout << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << "top: " << CQ.front() << endl;
		cout << "pop: " << CQ.pop_front() << endl;
		cout << endl;
	}
	cout << "empty: " << CQ.empty() << endl;

	return 0;
}
