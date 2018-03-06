#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
using namespace std;

class MyStack
{
public:
	void push(int x)
	{
		queue<int> tempQ;
		tempQ.push(x);
		while (!_data.empty())
		{
			tempQ.push(_data.front());
			_data.pop();
		}
		while (!tempQ.empty())
		{
			_data.push(tempQ.front());
			tempQ.pop();
		}
	}
	int pop()
	{
		int x = _data.front();
		_data.pop();
		return x;
	}
	int top()
	{
		return _data.front();
	}
	bool empty()
	{
		return _data.empty();
	}
private:
	queue<int> _data;
};



class MyQueue
{
public:
	//MyQueue()
	void push(int x)
	{
		inStack.push(x);
	}
	int pop()
	{
		if (outStack.empty()) 
		{
			while (!inStack.empty())
			{
				outStack.push(inStack.top());
				inStack.pop();
			}
		}
		int x = outStack.top();
		outStack.pop();
		return x;
	}
	int peek()
	{
		if (outStack.empty())
		{
			while (!inStack.empty())
			{
				outStack.push(inStack.top());
				inStack.pop();
			}
		}
		return outStack.top();
		
	}
	bool empty()
	{
		return (inStack.empty() && outStack.empty());
	}
private:
	stack<int> inStack, outStack;
};

class MinStack
{
public:
	MinStack(){}

	void push(int x)
	{
		if (minStack.empty() || minStack.top() > x)
			minStack.push(x);
		else minStack.push(minStack.top());
		_data.push(x);
	}
	void pop()
	{
		_data.pop();
		minStack.pop();
	}
	int top()
	{
		return _data.top();
	}
	int getMin()
	{
		return minStack.top();
	}
private:
	stack<int> _data, minStack;
};

int main()
{
	MyStack sk;
	sk.push(1);
	sk.push(2);
	sk.push(3);
	sk.push(4);
	system("pause");
	return 0;
}
