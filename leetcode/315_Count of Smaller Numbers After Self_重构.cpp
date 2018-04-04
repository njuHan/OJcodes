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
	vector<int> countSmaller(vector<int>& nums) {
		vector<pair<int, int>> num2idx;
		for (int i = 0; i < nums.size(); i++) num2idx.emplace_back(pair<int, int>{nums[i], i});
		this->cnt = vector<int>(nums.size(), 0);

		mergeSort(num2idx, 0, nums.size());
		return cnt;
	}
private:
	vector<int> cnt;
	//merge the sorted two vec: [i,mid), [mid, j)
	// and store the result in vec
	//左闭右开写起来方便
	void merge(vector<pair<int, int>>& vec, int i, int mid, int j)
	{
		// [vec[i], vec[mid]) 左闭右开
		vector<pair<int, int>> v1(&vec[i], &vec[mid]);
		vector<pair<int, int>> v2(&vec[mid], &vec[j]);
		int len1 = mid - i , len2 = j - mid;
		int k = i, p = 0, q = 0;
		while (p < len1 || q < len2)
		{
			// 从v1中选取
			if (q >= len2 || (p < len1 && v1[p].first <= v2[q].first))
			{
				cnt[v1[p].second] += q;
				vec[k++] = v1[p++];
			}
			else  
			{
				vec[k++] = v2[q++];
			}
		}
	}
	void mergeSort(vector<pair<int, int>>& vec, int i, int j) //[i, j )
	{
		if (j-i>1)
		{
			int mid = i + (j - i) / 2;
			mergeSort(vec, i, mid);
			mergeSort(vec, mid, j);
			merge(vec, i, mid, j);
		}
	}
};



int main()
{



	system("pause");
	return 0;
}



