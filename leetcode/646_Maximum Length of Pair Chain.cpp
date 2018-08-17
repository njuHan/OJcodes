class Solution {
public:
	int findLongestChain(vector<vector<int>>& pairs) {
		sort(pairs.begin(), pairs.end(), [](vector<int>& lhs, vector<int>& rhs) {return lhs[1] < rhs[1]; });
		int ans = 0;
		for (int i = 0, j = 0; j < pairs.size(); j++)
		{
			if (j == 0 || pairs[i][1] < pairs[j][0])
			{
				ans++;
				i = j;
			}
		}
		return ans;
	}

};