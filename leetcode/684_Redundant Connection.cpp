#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
using namespace std;

int pa[1005];
class Solution2 {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for (int i=1; i<=n; i++) pa[i] = i;
        for (auto e : edges)
        {
            int x = find(e[0]), y = find(e[1]);
            if (x==y) return {e[0], e[1]};
            else pa[x] = y;
        }
        return {};
    }
private:
    int find(int x)
    {
        return pa[x] == x ? x : pa[x] = find(pa[x]);
    }
};

class Solution {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		for (auto e : edges)
		{
			int x = find(e[0]), y = find(e[1]);
			if (x == y)
				return { e[0], e[1] };
			else
				pa[x] = y;
		}
	}
private:
	unordered_map<int, int> pa;
	int find(int x)
	{
		if (pa.count(x) == 0) 
			return pa[x] = x;
		else
			return pa[x] == x ? x : pa[x] = find(pa[x]);
	}
};