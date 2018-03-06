/*
#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size();
		if (m > n) return findMedianSortedArrays(nums2, nums1);
		int L1, L2, R1, R2, C1, C2, lo = 0, hi = 2 * m;
		while (lo <= hi)
		{
			C1 = (lo + hi) / 2;
			C2 = m + n - C1;
			L1 = C1==0 ?INT_MIN: nums1[(C1 - 1) / 2];
			R1 = C1==2*m ? INT_MAX:nums1[C1 / 2];
			L2 = C2==0 ? INT_MIN:nums2[(C2 - 1) / 2];
			R2 = C2==2*n ? INT_MAX : nums2[C2 / 2];
			if (L1 > R2)
				hi = C1 - 1;
			else if (L2 > R1)
				lo = C1 + 1;
			else
				return (max(L1, L2) + min(R1, R2)) / 2.0;
		}

	}

	double findKthSortedArrays(vector<int>& nums1, vector<int>& nums2, int k) {
		int n = nums1.size();
		int m = nums2.size();
		if (n > m)   //保证数组1一定最短
			return findMedianSortedArrays(nums2, nums1);
		int L1, L2, R1, R2, c1, c2, lo = 0, hi = 2 * n;  //我们目前是虚拟加了'#'所以数组1是2*n长度
		while (lo <= hi)   //二分
		{
			c1 = (lo + hi) / 2;  //c1是二分的结果
			c2 = 2*k-1 - c1;
			if (c2 < 0)
			{
				hi = c1 - 1;
				continue;
			}
			if (c2 > 2 * m)
			{
				lo = c1 + 1;
				continue;
			}
			L1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];   //map to original element
			R1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
			L2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
			R2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

			if (L1 > R2)
				hi = c1 - 1;
			else if (L2 > R1)
				lo = c1 + 1;
			else
				break;
		}
		return (max(L1, L2) + min(R1, R2)) / 2.0;

	}
};

int main()
{
	Solution solu;
	vector<int> v1 = { 1,3,5,7,9 };
	vector<int> v2 = { 2,4,6,8,10 };
	double ans = solu.findMedianSortedArrays(v1, v2);
	double k = solu.findKthSortedArrays(v1, v2, 7);
	printf("%lf, %lf\n", ans, k);
	system("pause");
	return 0;
}
*/