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

// Employee info
class Employee {
public:
	// It's the unique ID of each node.
	// unique id of this employee
	int id;
	// the importance value of this employee
	int importance;
	// the id of direct subordinates
	vector<int> subordinates;
};

class Solution {
public:
	int getImportance(vector<Employee*> employees, int id) {
		for (auto e : employees)
			if (e != NULL) dict[e->id] = e;
		return dfs(employees, id);
	}
private:
	unordered_map<int, Employee*> dict;
	int dfs(vector<Employee*>& employees, int id)
	{
		if (!dict.count(id)) return 0;
		int ans = dict[id]->importance;
		for (int sub : dict[id]->subordinates)
			ans += dfs(employees, sub);
		return ans;
	}
};