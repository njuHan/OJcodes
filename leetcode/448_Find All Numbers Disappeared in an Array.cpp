#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>
#include<functional>
using namespace std;

// swap method
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i=0, n = nums.size();
        vector<int> ans;
        while(i<n)
        {
            if (nums[i] != i+1 && nums[i]!=nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
            else i++;
        }
        for (int i=0; i<n; i++) if (nums[i]!=i+1) ans.push_back(i+1);
        return ans;
    }
};
// abs method
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i=0; i<n; i++)
        {
            int val = abs(nums[i]);
            if (nums[val-1]>0) nums[val-1] = -nums[val-1];
        }
        for (int i=0; i<n; i++) if (nums[i]>0) ans.push_back(i+1);
        return ans;
    }
};

class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++)
		{
			int idx = (nums[i]>0 ? nums[i]:-nums[i]) - 1;
			nums[idx] = nums[idx]>0 ? -nums[idx] : nums[idx];
		}
		vector<int> ans;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > 0)
				ans.push_back(i + 1);
		}
		return ans;
	}
};

int main()
{

	return 0;
}