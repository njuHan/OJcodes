#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		//按照h 从大到小排序，若h一样,按k值从小到大
		//lambda
		//或者取个名字：
		//auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) {return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second); };
		sort(people.begin(), people.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second); });
		vector<pair<int, int>> ans;
		for (auto p : people)
		{
			ans.insert(ans.begin() + p.second, p);
		}
		return ans;
	}
};

int main() {
	
	

	system("pause");
	return 0;
}
