// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/discuss/119879/C++JavaPython-Easy-Understood-DP-Solution
class Solution {
public:
	int minSwap(vector<int>& A, vector<int>& B) {
		int n = A.size();
		int swap[1000] = { 0 }, notswap[1000] = { 0 };
		swap[0] = 1; // exchange A[0] ans B[0]
		for (int i = 1; i < n; i++)
		{
			// initial 
			swap[i] = notswap[i] = n;
			if (A[i - 1] < A[i] && B[i - 1] < B[i])
			{
				notswap[i] = notswap[i - 1];
				swap[i] = swap[i - 1] + 1;
			}
			if (A[i - 1] < B[i] && B[i - 1] < A[i])
			{
				notswap[i] = min(swap[i - 1], notswap[i]);
				swap[i] = min(swap[i], notswap[i - 1] + 1);
			}
		}
		return min(swap[n - 1], notswap[n - 1]);
	}
};