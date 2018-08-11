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
#include<algorithm>
using namespace std;


class Solution {
public:
	int numRescueBoats(vector<int>& people, int limit) {
		sort(people.begin(), people.end());
		int n = people.size(), ans = 0;
		int i = 0, j = n - 1;
		while (i<j)
		{
			if (people[i] + people[j] <= limit) ans++, i++, j--;
			else ans++, j--;
		}
		ans += (i == j);
		return ans;
	}
};
