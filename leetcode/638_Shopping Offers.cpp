#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<list>
#include<ctime>
#include<numeric>
using namespace std;


class Solution {
public:
	int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
		pr = price;
		sp = special;
		nd = needs;
		mincost = INT_MAX;
		search(0, 0, needs);
		int nonsp = 0;
		for (int i = 0; i<pr.size(); i++) nonsp += pr[i] * nd[i];
		return min(nonsp, mincost);
	}
private:
	vector<int> pr;
	vector<vector<int>> sp;
	vector<int> nd;
	int mincost;
	void search(int cur, int cost, vector<int>& remain)
	{
		//cout<<cur<<endl;
		if (cur == sp.size())
		{
			for (int i = 0; i<pr.size(); i++)
			{
				cost += remain[i] * pr[i];
			}
			mincost = min(mincost, cost);
			//cout<<cost<<endl;
			return;
		}
		for (int i = cur; i < sp.size(); i++)
		{
			int j = 0;
			vector<int> temp(remain);
			for (; j < pr.size(); j++)
			{
				if ((temp[j] -= sp[i][j]) < 0) break;
			}
			if (j == nd.size()) search(i, cost + sp[i].back(), temp);
			else if (i == sp.size() - 1) search(i + 1, cost, remain);
		}
	}
};

//ÖØÔØ²Ù×÷·û
void operator += (vector<int>& a, vector<int>& b)
{
	for (int i = 0; i < a.size(); i++)
		a[i] += b[i];
}
void operator -= (vector<int>& a, vector<int>& b)
{
	for (int i = 0; i < a.size(); i++)
		a[i] -= b[i];
}
bool operator < (const vector<int>& a, const vector<int>& b)
{
	for (int i = 0; i < a.size(); i++)
		if (a[i] < b[i]) return true;
	return false;
}
int operator * (const vector<int>& a, const vector<int>& b)
{
	int ans = 0;
	for (int i = 0; i < a.size(); i++)
		ans += a[i] * b[i];
	return ans;
}

class Solution2 {
public:
	int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
		return shoppingOffers(price, special, needs, 0);
	}
private:
	
	int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int cost) 
	{
		int m = needs*price + cost;
		for (auto sp : special)
		{
			if (needs<sp || cost + sp.back() > m) continue; //pruning
			needs -= sp;
			m = min(m, shoppingOffers(price, special, needs, cost + sp.back()));
			needs += sp;
		}
		return m;
	}

};


int main()
{
	Solution solu;
	return 0;
}
