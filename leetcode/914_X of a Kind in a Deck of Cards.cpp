class Solution {
public:
	bool hasGroupsSizeX(vector<int>& deck) {
		int n = deck.size();
		if (n < 2) return 0;
		unordered_map<int, int> cnt;
		for (int& num : deck) cnt[num]++;
		int ans = cnt.begin()->second;
		for (auto& e : cnt)
			ans = gcd(ans, e.second);
		return ans > 1;
	}
private:
	int gcd(int a, int b)
	{
		return b == 0 ? a : gcd(b, a%b);
	}
};