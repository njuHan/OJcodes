#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len1 = nums1.size(), len2 = nums2.size();
		int k = (len1 + len2) / 2;
		if ((len1 + len2) % 2) return findKthSortedArrays(nums1, 0, len1, nums2, 0, len2, k+1);
		else return (findKthSortedArrays(nums1, 0, len1, nums2, 0, len2, k) + findKthSortedArrays(nums1, 0, len1, nums2, 0, len2, k + 1)) / 2.0;
	
	}
	//找到第K个数,注意这里k不是从0开始的下标，注意有起始下标start1,start2
	double findKthSortedArrays(vector<int>& nums1, int start1, int len1, vector<int>& nums2, int start2, int len2, int k)
	{
		if (len1 > len2) return findKthSortedArrays(nums2, start2, len2, nums1, start1, len1, k);
		if (len1 == 0) return nums2[start2 + k - 1];
		if (k == 1) return min(nums1[start1], nums2[start2]);
		int p1 = min(k / 2, len1); //元素个数p1,p2, p1+p2 == k
		int p2 = k - p1;
		if (nums1[start1+p1-1] == nums2[start2+p2-1]) //注意p1,p2等于0时，越界，所以判断k值是否等于1
			return (double)nums1[start1+p1-1];
		if (nums1[start1+p1 - 1] > nums2[start2+p2 - 1])
			return findKthSortedArrays(nums1, start1, len1, nums2, start2 + p2, len2 - p2, k - p2);
		else
			return findKthSortedArrays(nums1, start1 + p1, len1 - p1, nums2, start2, len2, k - p1);
	}
};

int main()
{
	Solution solu;
	vector<int> v1 = { 1,3,5,7,9 };
	vector<int> v2 = { 2,4,6,8 };
	double ans = solu.findMedianSortedArrays(v1, v2);
	
	printf("%lf\n", ans);
	system("pause");
	return 0;
}