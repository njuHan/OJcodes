#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<map>
#include<set>
#include<algorithm> 
#include<string>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		int len1 = nums1.size(), len2 = nums2.size();
		if (len1 > len2) return intersect(nums2, nums1);
		unordered_map<int, int> cnt;
		vector<int> ans;
		for (int e : nums1)
			cnt[e]++;
		for (int e : nums2)
			if (cnt.count(e) && cnt[e]-- > 0) 
				ans.push_back(e);
		return ans;
	}
};

int main()
{
	vector<int> num1 = { 1,2,2,1 }, num2 = { 2,2 };
	auto a = (num2, num1);
	return 0;
}