#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<assert.h>
using namespace std;


template<class T>
class SeqQueue
{
protected:
	int front, rear;
	T* elements;
	int maxsize;
public:
	SeqQueue(int sz=10):front(0),rear(0),maxsize(sz)
	{
		elements = new T[maxsize];
		assert(elements != NULL);
	}
	~SeqQueue() { delete[] elements; }
	bool isEmpty() const
	{
		return front == rear;
	}
	bool isFull() const
	{
		return (rear + 1) % maxsize == front;
	}
	bool enQueue(const T& x)
	{
		if (isFull()) return false;
		elements[rear] = x;
		rear = (rear + 1) % maxsize;
		return true;
	}
	bool deQueue(T& x)
	{
		if (isEmpty()) return false;
		x = elements(front);
		front = (front + 1) % maxsize;
		return true;
	}
	bool getFront(T& x) const
	{
		if (isEmpty()) return false;
		x = elements[front];
		return true;
	}
	friend ostream& operator << (ostream& os, SeqQueue<T>& q) //±ØÐëÓÑÔªº¯Êý
	{
		os << "front = " << q.front << ", rear = " << q.rear << endl;
		for (int i = q.front; i != q.rear; i = (i + 1) % q.maxsize)
			os << i << ":" << q.elements[i] << endl;
		return os;
	}
	
};



int main()
{
	SeqQueue<int> que;
	system("pause");
	return 0;
}
