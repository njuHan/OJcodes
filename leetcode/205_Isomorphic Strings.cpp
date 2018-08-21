class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<int, int> s2t , t2s;
        for (int i=0; i<s.length(); i++)
        {
            if (s2t.count(s[i]) && s2t[s[i]]!=t[i]) return false;
            if (t2s.count(t[i]) && t2s[t[i]]!=s[i]) return false;
            s2t[s[i]] = t[i];
            t2s[t[i]] = s[i];
        }
        return true;
    }
};