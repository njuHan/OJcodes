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

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> st(nums1.begin(), nums2.end());
		vector<int> ans;
		for (int num : nums2)
		{
			if (st.erase(num))
				ans.emplace_back(num);
		}
		return ans;
	}
};