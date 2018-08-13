class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        vector<string> buckets(s.length()+1, ""); //出现 1~n次
        for (char& ch : s) cnt[ch]++;
        for (auto& e : cnt)
            buckets[e.second].append(e.second, e.first);
        string ans = "";
        for (int i = s.length(); i>0; i--) 
            if (buckets[i].length()) ans += buckets[i];
        return ans;
    }
};