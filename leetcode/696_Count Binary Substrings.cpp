class Solution {
public:
    int countBinarySubstrings(string s) {
        int prelen = 0, curlen = 0, cnt = 0;
        for (int i=0; i<s.length(); i++)
        {
            if (i>0 && s[i-1]!=s[i])
            {
                prelen = curlen;
                curlen = 1;
            }
            else
                curlen++;
            cnt += prelen>=curlen;
        }
        return cnt;
    }
};