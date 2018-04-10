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
	int findCircleNum(vector<vector<int>>& M) {
		int cc, len;
		cc = len = M.size();
		pa.resize(len, 0);
		for (int i = 0; i < len; i++)
			pa[i] = i;
		for (int i = 0; i < len; i++)
			for (int j = i + 1; j < len; j++)
			{
				if (M[i][j])
				{
					int p1 = findSet(i);
					int p2 = findSet(j);
					if ( p1 != p2)
					{
						pa[p1] = p2;
						cc--;
					}
				}
			}
		return cc;
	}
private:
	vector<int> pa;
	int findSet(int x)
	{
		return pa[x] == x ? x : (pa[x] = findSet(pa[x]));
	}
};

int main()
{

	system("pause");
	return 0;
}



