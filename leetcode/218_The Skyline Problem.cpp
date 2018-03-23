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
	//核心思想： 维护一个当前有效高度的集合，
	//若当前有效高度集合的最大高度和当前地平线不同，修改地平线起始点和高度
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		//存储当前有效的高度，利用set的自动排序性质，最大高度是最后一个元素
		//遇到一个新房子的开始，添加其高度，
		//遇到房子的结束，删除其高度
		multiset<int> heights = { 0 };
		//记录房子起始和结束时的idx 和 高度 的二元组
		//例如 [2,4,3], 记为(2,-3), (4,3)
		// 符号用于区分起始和结束
		// 起始高度为负数，利用set有序性，使得两个高度一样房子且相邻的房子，第二个房子先起始push 高度，再pop第一个房子的高度
		//自动合并了两个相邻的房子
		multiset<pair<int, int>> idxHeight;
		//当前起始位置，和起始的高度
		pair<int, int> cur({ 0, 0 });
		//ans:
		vector<pair<int, int>> ans;
		for (auto e : buildings)
		{
			idxHeight.insert(pair<int, int>(e[0], -e[2])); //左，-高度
			idxHeight.insert(pair<int, int>(e[1], e[2])); // 右，高度
		}
		for (auto e : idxHeight)
		{
			if (e.second < 0) //遇到房子的起始
				heights.insert(-e.second);
			else //房子结束，删除房子高度
			{
				//heights.erase(e.second); 不能直接删除key,这样会把所有key都删了
				//只能删除一个：
				heights.erase(heights.find(e.second));
			}
			if (*heights.rbegin() != cur.second)
			{
				cur.first = e.first;
				cur.second = *heights.rbegin();
				ans.emplace_back(cur);
			}
			
		}
		return ans;
	}


};
int main()
{

	Solution solu;
	vector<vector<int>> vec = { {0,2,3},{2,5,3} };
	solu.getSkyline(vec);
	system("pause");
	return 0;
}