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
	//2 passes, O(n) space
	int longestMountain(vector<int>& A) {
		int n = A.size(), ans = 0;
		vector<int> up(n, 0), down(n, 0);
		for (int i = 1; i < n; i++)
			up[i] = A[i] > A[i - 1] ? up[i - 1] + 1 : 0;
		for (int i = n - 2; i >= 0; i--)
		{
			down[i] = A[i] > A[i + 1] ? down[i + 1] + 1 : 0;
			down[i] && up[i] && (ans = max(ans, down[i] + up[i] + 1));
		}
		return ans;
	}
};

class Solution2 {
public:
	//1 pass, O(1) space
	int longestMountain(vector<int>& A) {
		int down = 0, up = 0, ans = 0;
		for (int i = 1; i < A.size(); i++)
		{
			//相等 || 在下降的过程中遇到上升
			if (A[i] == A[i - 1] || (down>0 && A[i - 1] < A[i])) down = up = 0;
			if (A[i] > A[i - 1]) up++;
			if (A[i] < A[i - 1]) down++;
			if (down && up) ans = max(ans, down + up + 1);
		}
		return ans;
	}
};

