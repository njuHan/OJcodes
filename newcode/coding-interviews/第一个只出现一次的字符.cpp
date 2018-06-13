class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char, int> cnt;
		for (char ch : str) cnt[ch]++;
		for (int i = 0; i < str.length(); i++)
			if (cnt[str[i]] == 1) return i;
		return -1;
    }
};