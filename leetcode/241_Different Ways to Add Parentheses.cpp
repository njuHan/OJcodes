class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		if (cache.count(input)) return cache[input];
		vector<int> vec;
		for (int i = 0; i<input.length(); i++)
		{
			if (!isdigit(input[i]))
			{
				for (int a : diffWaysToCompute(input.substr(0, i)))
					for (int b : diffWaysToCompute(input.substr(i + 1)))
					{
						int res = input[i] == '+' ? a + b : (input[i] == '-' ? a - b : a*b);
						vec.push_back(res);
					}
			}
		}
		return cache[input] = (vec.size() ? vec : vector<int>{stoi(input)});
	}
private:
	unordered_map<string, vector<int>> cache;
};