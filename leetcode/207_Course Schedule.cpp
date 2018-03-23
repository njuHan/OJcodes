#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<queue>
using namespace std;



class Solution {
public:
	// [1,0]
	// To take course 1 you should have finished course 0
	//有向边 0->1
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		if (numCourses == 0) return true;
		set<int> ans;
		for (int i = 0; i < numCourses; i++) zeroNode.insert(i);
		//如果 graph[i][j]==true，表示有向边i->j
		graph = vector<vector<bool>>(numCourses, vector<bool>(numCourses, false));
		for (int i = 0; i < prerequisites.size(); i++)
		{
			int u = prerequisites[i].second, v = prerequisites[i].first;
			if (u == v) return false; //has cycle
			graph[u][v] = true;
			inDgree[v] = inDgree[v]+1;
			zeroNode.erase(v);
		}
		// BFS
		while (!zeroNode.empty())
		{
			int u = *zeroNode.begin();
			zeroNode.erase(u);
			ans.insert(u);
			for (int v = 0; v < numCourses; v++)
			{
				if (graph[u][v])
				{
					inDgree[v] -= 1;
					if (inDgree[v] == 0) zeroNode.insert(v);
				}
			}
		}
		if (ans.size() == numCourses) return true;
		else return false;

	}
	// 代码重构, 这样更慢了。。。
	bool canFinish2(int numCourses, vector<pair<int, int>>& prerequisites) {
		if (numCourses == 0) return true;
		//如果 graph[i][j]==true，表示有向边i->j
		graph = vector<vector<bool>>(numCourses, vector<bool>(numCourses, false));
		for (int i = 0; i < prerequisites.size(); i++)
		{
			int u = prerequisites[i].second, v = prerequisites[i].first;
			if (u == v) return false; //has cycle
			graph[u][v] = true;
			inDgree[v] = inDgree[v] + 1;
			
		}
		// BFS
		// 找到 numCourses个入度为0的点
		for (int i = 0; i < numCourses; i++)
		{
			int j;
			for (j = 0; j < numCourses; j++)
			{
				if (inDgree[j] == 0)
				{
					inDgree[j] = -1;
					break;
				}
			}
			if (j == numCourses) return false; //找不到入度为0的点
			for (int v = 0; v < numCourses; v++) //下一个结点入度减一
				if (graph[j][v])
					inDgree[v] -= 1;
		}
		return true;

	}
private:
	vector<vector<bool>> graph;
	//结点的入度
	map<int,int> inDgree; 
	//入度为0的结点
	set<int> zeroNode;
};
int main()
{


	system("pause");
	return 0;
}