#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;


class Solution2 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        st = unordered_set<int>(nums.begin(), nums.end());
        vector<int> cur = {};
        search(cur, nums);
        return ans;
    }
private:
    unordered_set<int> st;
    vector<vector<int>> ans;
    void search(vector<int>& cur, vector<int>& nums)
    {
        if (cur.size() == nums.size()) {ans.emplace_back(cur); return;}
        for (int& num : nums)
        {
            if (st.count(num))
            {
                cur.emplace_back(num);
                st.erase(num);
                search(cur, nums);
                cur.pop_back();
                st.insert(num);
            }
        }
        
    }
};


class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<int> vec;
		search(nums, 0, vec);
		return ans;
	}
	void search(vector<int>& nums, int cur, vector<int>& curVec)
	{
		if (cur == nums.size())
		{
			ans.push_back(curVec);
			return;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			vector<int>::iterator it = find(curVec.begin(), curVec.end(), nums[i]);
			if (it == curVec.end())
			{
				curVec.push_back(nums[i]);
				search(nums, cur + 1, curVec);
				curVec.pop_back();
			}
		}
	}
private:
	vector<vector<int>> ans;
};
int main()
{
	Solution solu;
	vector<int > vec = { 1,2,3 };
	vector<vector<int>> ans = solu.permute(vec);
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
			printf("%d, ", ans[i][j]);
		printf("\n");
	}
	system("pause");
	return 0;
}