#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
#include<set>
using namespace std;

class Solution {
public:
	int minSwapsCouples2(vector<int>& row) {
		for (int& e : row) e = e >> 1;
		vector<int>::iterator it = row.begin();
		int ans = 0;
		for (; it != row.end(); it += 2)
		{
			if (*it != *(it + 1))
			{
				vector<int>::iterator toswap = find(it + 2, row.end(), *it);
				iter_swap(it + 1, toswap);
				ans++;
			}
		}
		return ans;
	}
	int minSwapsCouples(vector<int>& row) {
		int len = row.size();
		vector<int> pos(len, 0);
		int ans = 0;
		for (int i = 0; i < len; i++) pos[row[i]] = i;
		for (int i = 0; i < len; i += 2)
		{
			if (row[i] >> 1 == row[i + 1] >> 1) continue;
			//’“µΩrow[i]µƒ¡Ì“ª∞Î
			int tofind = row[i] % 2 == 0 ? row[i] + 1: row[i] - 1;
			int idx = pos[tofind];
			ans++;
			//swap(pos[tofind], pos[row[i + 1]]);
			pos[row[i + 1]] = idx;
			swap(row[i + 1], row[idx]);
			
		}
		return ans;
	}
};

int main()
{

	vector<int> vec = { 10,7,4,2,3,0,9,11,1,5,6,8 };
	int ans = Solution().minSwapsCouples(vec);

	system("pause");
	return 0;
}



