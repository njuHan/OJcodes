int a[26] = {0};
class Solution {
public:
    char findTheDifference(string s, string t) {
        memset(a, 0, sizeof(a));
        for (char& ch : t) a[ch-'a']++;
        for (char& ch : s) a[ch-'a']--;
        for (int i=0; i<26; i++) if (a[i]) return i + 'a';
    }
};