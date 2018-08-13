#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> minHeap;
		for (int i = 0; i < nums.size(); i++)
		{
			if (minHeap.size() < k)
				minHeap.push(nums[i]);
			else if (minHeap.top() < nums[i])
			{
				minHeap.pop();
				minHeap.push(nums[i]);
			}
		}
		return minHeap.top();
	}
};

class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int x = 0, y = nums.size();
        while(x<y)
        {
            int mid = split(nums, x, y);
            if (mid==k-1) return nums[mid];
            else if (mid>k-1) y = mid;
            else x = mid+1;
        }
        return -1;
    }
private:
    int split(vector<int>& nums, int x, int y)
    {
        int pivot = x, val = nums[x];
        for (int i=x; i<y; i++)
        {
            if (nums[i]>val) swap(nums[i], nums[++pivot]);
        }
        swap(nums[x], nums[pivot]);
        return pivot;
    }
};

int main()
{
	
	system("pause");
	return 0;
}
