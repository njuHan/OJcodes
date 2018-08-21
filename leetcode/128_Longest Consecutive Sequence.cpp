#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

class Solution2 {
public:
    int longestConsecutive(vector<int>& nums) {
        // 设有连续序列[i,j]， 长度为s, 在边界元素上记录长度
        // len[i] = len[j] = s
        unordered_map<int, int> len;
        int ans = 0;
        for (int& i : nums)
        {
            if (len[i]) continue; //这里不能使用 count, len[i]可能为0
            ans = max(ans, len[i] = len[i-len[i-1]] = len[i+len[i+1]] = len[i-1] + len[i+1] + 1);
        }
        return ans;
    }
};

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_map<int, int> num2cons;
		int cnt = 0;
		for (auto e : nums)
		{
			if (num2cons[e] == 0)
			{
				num2cons[e] = num2cons[e-num2cons[e-1]] = num2cons[e+num2cons[e+1]] = num2cons[e - num2cons[e - 1]] + num2cons[e + num2cons[e + 1]] + 1;
				cnt = cnt < num2cons[e] ? num2cons[e] : cnt;
			}
		}
		return cnt;
	}
};

int main()
{
	Solution solu;
	vector<int> vec = { 100, 4, 200, 1, 3, 2 };
	int ans = solu.longestConsecutive(vec);
	cout << ans;
	
	system("pause");
	return 0;
}