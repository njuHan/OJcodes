#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> ans;
		if (num < 0) return ans;
		ans.resize(num + 1);
		ans[0] = 0;
		int k = 0;
		for (int i = 1; i <= num; i++)
		{
			if (i == 1 << k)
			{
				ans[i] = 1;
				k++;
			}
			else if (i % 2 == 1)
				ans[i] = ans[i - 1] + 1;
			else
				ans[i] = 1 + ans[i - (1 << (k - 1))];
		}
		return ans;
	}

	vector<int> countBits2(int num) {
		vector<int> ret(num + 1, 0);
		for (int i = 1; i <= num; ++i)
			ret[i] = ret[i&(i - 1)] + 1;
		return ret;
	}

	vector<int> countBits3(int num) {
		vector<int> res(num + 1, 0);
		for (int i = 1; i <= num; i++)
			res[i] = i & 1 ? res[i - 1] + 1 : res[i >> 1];
		return res;
	}
	
};

int main()
{
	return 0;
}