class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 0, maxlen = 0;
		vector<int> len(n, 0), cnt(n, 0);
		for (int i = 0; i < n; i++)
		{
			len[i] = cnt[i] = 1;
			for (int j = 0; j < i; j++)
			{
				if (nums[j] < nums[i])
				{
					if (len[j] + 1 == len[i]) cnt[i] += cnt[j];
					else if (len[j] + 1 > len[i]) cnt[i] = cnt[j], len[i] = len[j] + 1;
				}
			}
			if (maxlen == len[i]) ans += cnt[i];
			else if (maxlen < len[i]) ans = cnt[i], maxlen = len[i];
		}
		return ans;
    }
};