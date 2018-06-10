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
	int FindGreatestSumOfSubArray(vector<int> array) {
		int len = array.size();
		int pre = array[0], cur , maxsum = array[0];
		for (int i = 1; i < len; i++)
		{
			cur = array[i] + max(0, pre);
			maxsum = max(maxsum, cur);
			pre = cur;
		}
		return maxsum;
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