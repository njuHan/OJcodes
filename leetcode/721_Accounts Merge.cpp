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
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
		//将第一个邮箱作为parent, 并查集、所属关系owner初始化
		for (auto& e : accounts)
		{
			string name = e[0], p = find(e[1]);
			for (int i = 1; i < e.size(); i++) 
			{
				parent[find(e[i])] = p;
				owner[e[i]] = name;
			}
		}
		for (auto& e : accounts)
		{
			string parent = find(e[1]);
			for (int i = 1; i < e.size(); i++)
			{
				mails[parent].insert(e[i]);
			}
		}
		vector<vector<string>> ans;
		for (auto& e : mails)
		{
			vector<string> temp(e.second.begin(), e.second.end());
			temp.insert(temp.begin(), owner[e.first]);
			ans.emplace_back(temp);
		}
		return ans;
	}
private:
	unordered_map<string, string> parent, owner;
	unordered_map<string, set<string>> mails; //mails[parent] = son;
	string find(string x)
	{
		if (!parent.count(x)) return parent[x] = x;
		return parent[x] == x ? x : parent[x] = find(parent[x]);
	}
};