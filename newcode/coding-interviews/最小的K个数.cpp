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
#include<ctime>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		priority_queue<int, vector<int>, less<int>> maxHeap; 
		vector<int> ans;
		if (k <= 0 || input.size()<k) return ans;
		for (int num : input)
		{
			if (maxHeap.size() < k) maxHeap.push(num);
			else
			{
				maxHeap.push(num);
				maxHeap.pop();
			}
		}
		while (!maxHeap.empty())
		{
			ans.push_back(maxHeap.top()); maxHeap.pop();
		}
		return ans;
	}
};

int main()
{
	string str = "abc";
	Solution solu;
	vector<string> ans = solu.Permutation(str);
	system("pause");
	return 0;
}