#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int  i= 0 , j = 0, len = nums.size();
		if (len < 1) return;
		while (i<len && nums[i] != 0) i++;
		j = i;
		while (j<len && nums[j] == 0) j++;
		while (i<len && j<len)
		{
			swap(nums[i], nums[j]);
			while (i<len && nums[i] != 0) i++;
			j = i;
			while (j<len &&nums[j] == 0) j++;
		}
		return;
	}

	void moveZeroes2(vector<int>& nums) {
		fill(remove(nums.begin(), nums.end(), 0), nums.end(), 0);
	}

	void moveZeroes3(vector<int>& nums) {
		int lastNonZeroFoundAt = 0;
		// If the current element is not 0, then we need to
		// append it just in front of last non 0 element we found. 
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != 0) {
				nums[lastNonZeroFoundAt++] = nums[i];
			}
		}
		// After we have finished processing new elements,
		// all the non-zero elements are already at beginning of array.
		// We just need to fill remaining array with 0's.
		for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
			nums[i] = 0;
		}
	}
	/*optimal solution
	All elements before the slow pointer (i) are non-zeroes.
	All elements between the j and slow pointer are zeroes.
	*/
	void moveZeroes4(vector<int>& nums) {
		int len = nums.size();
		int i, j;
		for (int i = 0, j = 0; j < len; j++)
		{
			if (nums[j] != 0)
				swap(nums[i++], nums[j]);
		}
	}

};


int main()
{
	
	system("pause");
	return 0;
}



