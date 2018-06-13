class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), [](int lhs, int rhs) {return to_string(lhs) + to_string(rhs) < to_string(rhs) + to_string(lhs); });
		string ans;
		for (int num : numbers)
			ans += to_string(num);
		return ans;
    }
};