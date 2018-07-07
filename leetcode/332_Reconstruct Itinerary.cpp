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

/*
Eulerian Path.if the Eulerian Path of graph exists,it does not change.
so if we get Itinerary randomly,all of them have same length.
then if we get itinerary by lexical order,we'll get a itinerary that has smallest lexical order than others.
*/

class Solution {
public:
	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		for (auto ticket : tickets) dest[ticket.first].insert(ticket.second);
		vist("JFK");
		return vector<string>(ans.rbegin(), ans.rend());
	}
private:
	unordered_map<string, multiset<string>> dest;
	vector<string> ans;
	void vist(string from)
	{
		while (dest[from].size())
		{
			string to = *dest[from].begin();
			dest[from].erase(dest[from].begin());
			vist(to);
		}
		ans.emplace_back(from);
	}
};