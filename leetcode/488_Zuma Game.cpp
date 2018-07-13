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

// https://leetcode.com/problems/zuma-game/discuss/97033/16-line-9ms-recursive-solution-with-pre-process-memorization-and-edge-case-test-no-helper-functions-(detailed-explanation)
//dfs with cache
class Solution {
public:
	int findMinStep(string board, string hand) {
		board = shrink(board);
		sort(hand.begin(), hand.end());
		if (cache.count(board) && cache[board].count(hand)) return cache[board][hand];
		//base case
		if (board.size() == 0) return 0;
		if (hand.length() == 0) return -1; 
		//edge case
		if (!isValid(board, hand)) return cache[board][hand] = -1;

		int ans = INT_MAX;
		for (int i = 0; i < hand.length(); i++)
		{
			//dfs 每次从hand选出不重复的元素hand[i]，并且hand[i]在board中出现
			if ( (i && hand[i - 1] == hand[i]) || board.find(hand[i]) == string::npos) continue;
			for (int j = 0; j < board.length(); j++)
			{
				if (hand[i] != board[j] || (j && board[j - 1] == board[j])) continue;
				string b(board), h(hand);
				b.insert(b.begin() + j, hand[i]);
				h.erase(h.begin() + i);
				int step = findMinStep(b, h);
				if (step != -1) ans = min(ans, step + 1);
			}
		}
		return cache[board][hand] = (ans == INT_MAX ? -1 : ans);
	}
private:
	unordered_map<string, unordered_map<string, int>> cache;
	string remove(string b)
	{
		if (b.length() < 3) return b;
		string a = "";
		char pre = b[0];
		int len = 1;
		for (int i = 1; i < b.length(); i++)
		{
			if (pre == b[i]) len++;
			else {
				if (len < 3) a.append(len, pre);
				len = 1;
				pre = b[i];
			}
		}
		if (len < 3) a.append(len, pre);
		return a;
	}
	string shrink(string str)
	{
		string a;
		while ((a = remove(str)) != str)
			str = a;
		return a;

	}
	bool isValid(string board, string hand)
	{
		string comb = board + hand;
		unordered_map<char, int> cnt;
		for (char& ch : comb) cnt[ch]++;
		for (char& ch : board) if (cnt[ch] < 3) return false;
		return true;
	}
};
