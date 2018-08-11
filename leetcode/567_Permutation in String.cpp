class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnts(26,0);
        for (char& ch : s1) cnts[ch-'a']++;
        int left = s1.length();
        for (int i=0, j=0; j<s2.size(); j++)
        {
            if (cnts[s2[j]-'a']-- > 0) left--;
            while(left==0)
            {
                if (j-i+1==s1.length()) return true;
                if (++cnts[s2[i++]-'a']>0) left++;
            }
        }
        return false;
    }
};