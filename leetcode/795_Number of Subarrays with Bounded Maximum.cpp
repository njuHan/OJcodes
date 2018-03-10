#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
	int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
		//所有<=R的连续子串数 - 所有<=L-1的连续子串数
		return cnt(A, R) - cnt(A, L - 1);
	}
	//计数 所有元素<=b的连续子串的个数
	//cur：当前i指向的元素所属的最大连续串(所有元素<=b)，有cur个以[i]结尾子串(<=b)
	// 那么当i+1元素<=b时，有cur+1个以[i+1]结尾的子串
	//总子串个数，就是这个连续子串的所有cur之和
	int cnt(vector<int>& A, int b)
	{
		int len = A.size();
		int cur = 0, sum = 0;
		for (int i = 0; i < len; i++)
		{
			if (A[i] <= b)
				cur = cur + 1; //子串延长
			else
				cur = 0; //子串中断结束
			sum += cur;
		}
		return sum;
	}
};
int main()
{
	vector<int> v = { 2, 1, 4, 3 };
	Solution solu;
	int ans = solu.numSubarrayBoundedMax(v, 2, 3);
	printf("%d\n", ans);
	system("pause");
	return 0;
}