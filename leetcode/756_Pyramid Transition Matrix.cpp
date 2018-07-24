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

// Letters in all strings will be chosen from the set {'A', 'B', 'C', 'D', 'E', 'F', 'G'}.
//小规模连续数据可以直接用数组，不需要map
unsigned char dict[7][7];
class Solution {
public:
	bool pyramidTransition(string bottom, vector<string>& allowed) {
		memset(dict, 0, sizeof(dict));
		for (string& str : allowed)
			dict[str[0] - 'A'][str[1] - 'A'] |= (1 << (str[2] - 'A'));
		return search(bottom, string(bottom.length() - 1, 0), 0);
	}
private:
	bool search(string curlevel, string nextlevel, int pos)
	{
		if (curlevel.length() == 1) return 1;
		if (pos == curlevel.length() - 1) return search(nextlevel, string(nextlevel.length() - 1, 0), 0);
		//cout<<curlevel<<", "<<pos<<endl;
		unsigned char bits = dict[curlevel[pos] - 'A'][curlevel[pos + 1] - 'A'];
		for (int i = 0; i < 7; i++)
		{
			if (bits & (1 << i))
			{
				nextlevel[pos] = 'A' + i;
				if (search(curlevel, nextlevel, pos + 1)) return true;
			}
		}
		return false;
	}
};