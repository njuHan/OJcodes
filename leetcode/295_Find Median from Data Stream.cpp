#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		if (maxHeap.empty())
			maxHeap.push(num);
		else if (maxHeap.size() == minHeap.size())
		{
			if (num <= minHeap.top())
				maxHeap.push(num);
			else
			{
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(num);
			}

		}
		else // max size  = min size +1
		{
			if (num >= maxHeap.top())
				minHeap.push(num);
			else
			{
				minHeap.push(maxHeap.top());
				maxHeap.pop();
				maxHeap.push(num);
			}
		}
		
	}

	double findMedian() {
		if (maxHeap.size() == minHeap.size())
			return (maxHeap.top() + minHeap.top()) / 2.0;
		else return maxHeap.top();
	}
private:
	// 最大堆的元素均小于最小堆的元素
	// 两个堆的元素相等，或者最大堆的元素多一个
	priority_queue<int, vector<int>, less<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
};


int main()
{
	MedianFinder mf;
	int test[] = { 6,10,1,7,99,4,33 };
	for (int i = 0; i < 7; i++)
	{
		mf.addNum(test[i]);
		printf("%lf\n", mf.findMedian());
	}
	system("pause");
	return 0;
}
