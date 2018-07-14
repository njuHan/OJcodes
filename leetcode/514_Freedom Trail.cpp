#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<list>
#include<sstream>
#include<functional>
#include<algorithm>
using namespace std;


class Solution {
public:
	int findRotateSteps(string ring, string key) {
		m = ring.length();
		r = ring, k = key;
		mem = vector<vector<int>>(m, vector<int>(key.length(), INT_MAX));
		return search(0, 0) + key.length();
	}
private:
	int m;
	string r, k;
	vector<vector<int>> mem;
	int search(int curi, int j)
	{
		if (j == k.length()) return 0;
		if (mem[curi][j] != INT_MAX) return mem[curi][j];
		int& ans = mem[curi][j];
		int i = curi;
		do
		{
			if (r[i] == k[j])
			{
				int dist = min((curi - i + m) % m, (i - curi + m) % m);
				//cout<<curi<<", "<<i<<", "<<j<<", "<<dist<<endl;
				ans = min(ans, dist + search(i, j + 1));
			}
		} while ( (i=(i+1)%m) != curi);
		return  ans;
	}
};

int main()
{
	string r = "caotmcaataijjxi", k = "oatjiioicitatajtijciocjcaaxaaatmctxamacaamjjx";
	Solution solu;
	int ans = solu.findRotateSteps(r, k);

	system("pause");
	return 0;
}