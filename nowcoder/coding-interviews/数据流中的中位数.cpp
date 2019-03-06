#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<list>
#include<sstream>
#include<functional>
using namespace std;

class Solution {
public:
	void Insert(int num)
	{
		int size1 = maxHeap.size(), size2 = minHeap.size();
		if (size1 == size2)
		{
			if (minHeap.empty() || minHeap.top() >= num)
				maxHeap.push(num);
			else
			{
				minHeap.push(num);
				maxHeap.push(minHeap.top());
				minHeap.pop();
			}
		}
		else //size1 = size2 + 1
		{
			if (num >= maxHeap.top())
				minHeap.push(num);
			else
			{
				maxHeap.push(num);
				minHeap.push(maxHeap.top());
				maxHeap.pop();
			}
		}
	}

	double GetMedian()
	{
		int size1 = maxHeap.size(), size2 = minHeap.size();
		if (size1 == size2)
			return ((double)maxHeap.top() + (double)minHeap.top()) / 2.0;
		else return maxHeap.top();
	}
private:
	priority_queue<int, vector<int>, less<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
};