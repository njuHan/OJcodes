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
#include<sstream>
using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode *cloneGraphBFS(UndirectedGraphNode *node) {
		if (node == NULL) return NULL;
		queue<UndirectedGraphNode*> que;
		que.push(node);
		mp[node] = new UndirectedGraphNode(node->label);
		while (!que.empty())
		{
			UndirectedGraphNode* p = que.front(); que.pop();
			for (auto adj : p->neighbors)
			{
				if (!mp.count(adj))
				{
					mp[adj] = new UndirectedGraphNode(adj->label);
					que.push(adj);
				}
				mp[p]->neighbors.push_back(mp[adj]);
			}
		}
		return mp[node];
	}
	//dfs
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
	{
		if (node == NULL) return NULL;
		if (!mp.count(node))
		{
			mp[node] = new UndirectedGraphNode(node->label);
			for (auto adj : node->neighbors)
				mp[node]->neighbors.push_back(cloneGraph(adj));
		}
		return mp[node];
	}
	
private:
	unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> mp;
};

int main()
{
	string str = "0 1 2#1 2#2 2", node, adj;
	istringstream in(str);
	while (getline(in, node, '#'))
	{
		istringstream temp(node);
		while (temp>>adj)
		{
			cout << adj << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
