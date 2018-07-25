#include<queue>
#include<exception>

using namespace std;

template <typename T> class CStack
{
public:
	CStack(){}
	~CStack(){}

	void push_back(const T& node);
	T pop_back();

private:
	queue<T> queue1;
	queue<T> queue2;
};

template<typename T> 
void CStack<T>::push_back(const T& node)
{
	if (queue1.size() > 0 && queue2.size() > 0)
	{
		throw new exception("can not push_back");
	}
	else
	{
		if (queue1.size() == 0)
		{
			queue2.push(node);
		}
		else
		{
			queue1.push(node);
		}
	}
}

template<typename T> 
T CStack<T>::pop_back()
{
	if (queue1.size() == 0 && queue2.size() == 0)
	{
		throw new exception("stack is empty");
	}

	T head;
	if (queue1.size() > 0)
	{
		while (queue1.size() > 1)
		{
			T& data = queue1.front();
			queue1.pop();
			queue2.push(data);
		}

		head = queue1.front();
		queue1.pop();
	}
	else
	{
		while (queue2.size() > 1)
		{
			T& data = queue2.front();
			queue2.pop();
			queue1.push(data);
		}

		head = queue2.front();
		queue2.pop();
	}

	return head;
}

void test(char actual, char expected)
{
	if (actual == expected)
		printf("Test passed.\n");
	else
		printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
	CStack<char> stack;

	stack.push_back('a');
	stack.push_back('b');
	stack.push_back('c');

	char res = stack.pop_back();
	test(res, 'c');

	res = stack.pop_back();
	test(res, 'b');

	stack.push_back('d');
	res = stack.pop_back();
	test(res, 'd');

	stack.push_back('e');
	res = stack.pop_back();
	test(res, 'e');

	res = stack.pop_back();
	test(res, 'a');

	return 0;
}
