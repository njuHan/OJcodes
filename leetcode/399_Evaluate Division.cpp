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
using namespace std;

class Solution {
public:
	vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
		unordered_map<string, unordered_map<string, double>> graph;
		int i = 0;
		for (auto& e : equations)
		{
			graph[e.first][e.second] = values[i];
			graph[e.second][e.first] = 1 / values[i];
			graph[e.first][e.first] = graph[e.second][e.second] = 1.0;
			i++;
		}
		//floyd
		for (auto& k : graph) //k.first 为连接分子分母的结点
			for (auto& i : graph[k.first])
				for (auto& j : graph[k.first])
				{
					if (i.first == j.first || graph[i.first].count(j.first)) continue;
					graph[i.first][j.first] = graph[i.first][k.first] * graph[k.first][j.first];
				}
		vector<double> ans;
		for (auto& q : queries)
		{
			if (graph.count(q.first) && graph[q.first].count(q.second)) ans.emplace_back(graph[q.first][q.second]);
			else ans.emplace_back(-1.0);
		}
		return ans;
	}
};

int main()
{
	double a = 1.0;
	a /= 5;
	a *= 5;
	cout << a << endl;
	system("pause");
	return 0;
}