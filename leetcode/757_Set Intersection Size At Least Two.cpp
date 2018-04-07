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

//solution https://leetcode.com/problems/set-intersection-size-at-least-two/discuss/113089/C++-concise-solution-O(nlogn)-greedy-39-ms
// 维护两个公共点p1,p2， 区间按照 end 升序排列，
//贪心：公共点取区间最后两个点，有最大的概率与之后的集合相交
//对于end一样的区间， 把区间小的(start较大)放在前面，能满足小区间的公共点，一定可以满足end一样的较大区间
/* eg:
[1,2]
  [2,3]
[1,2,3]
    [3,4]
  [2,3,4]
*/

class Solution {
public:
	int intersectionSizeTwo(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2) {return v1[1] < v2[1] || (v1[1] == v2[1] && v1[0] > v2[0]); });
		int ans = 0, p1 = -1, p2 = -1;
		for (auto& data : intervals)
		{
			if (data[0] <= p1) // contains p1 and p2;
				continue;
			else if (p2 < data[0]) //don't contain, update point
			{
				ans += 2;
				p2 = data[1];
				p1 = p2 - 1;
			}
			else //contains only p2
			{
				ans++;
				p1 = p2;
				p2 = data[1];
			}
		}
		return ans;
	}
};

int main()
{

	

	system("pause");
	return 0;
}



