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
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		stack<int> sk;
		for (int num : numbers)
		{
			if (sk.empty()) sk.push(num);
			else
			{
				if (sk.top() != num) sk.pop();
				else sk.push(num);
			}
		}
		if (sk.empty()) return 0;
		int num = sk.top(), cnt = 0;
		for (int i = 0; i < numbers.size(); i++)
			if (numbers[i] == num) cnt++;
		return cnt * 2 > numbers.size() ? num : 0;
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