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
	bool isPossible(vector<int>& nums) {
		map<int, int> numCnt;
		for (int e : nums) numCnt[e]++;
		while (numCnt.size())
		{
			map<int, int> temp(numCnt);
			int pre = temp.begin()->first;
			int cnt = temp.begin()->second;
			int len = 1;
			temp.begin()->second--;
			if (temp.begin()->second == 0) temp.erase(temp.begin());
			map<int, int>::iterator it = temp.begin();
			while (it != temp.end())
			{
				if (it->first == pre + 1 && it->second >= cnt)
				{
					len++;
					pre++;
					cnt = it->second;
					it->second--;
					if (it->second == 0)
						it = temp.erase(it);
				}
				else if (it->first == pre)
					it++;
				else break;
			}
			if (len >= 3)
			{
				swap(temp, numCnt);
			}
			else
				return false;
		}
		return true;
	}
};

int main()
{

	vector<int>  vec = { 1,2,3,3,4,5 };
	Solution solu;
	bool ans = solu.isPossible(vec);

	system("pause");
	return 0;
}



