class Solution {
public:
	vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
		unordered_map<char, int> need, temp;
		unordered_map<string, int> have;
		vector<string> ans;
		for (string& str : B)
		{
			temp.clear();
			for (char& ch : str) temp[ch]++;
			for (auto& e : temp)
				if (need[e.first] < e.second) need[e.first] = e.second;
		}
		for (string& str : A) have[str]++;
		for (auto& e : have)
		{
			temp.clear();
			for (char ch : e.first) temp[ch]++;
			unordered_map<char, int>::iterator it;
			for (it = need.begin(); it != need.end(); it++)
				if (temp[it->first] < it->second) break;
			if (it == need.end())
				for (int i = 0; i < e.second; i++) ans.emplace_back(e.first);
		}
		return ans;
	}
};