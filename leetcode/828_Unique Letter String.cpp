int idx[26][2];
class Solution {
public:
    int uniqueLetterString(string S) {
        int mod = 1e9+7, ans = 0;
        memset(idx, -1, sizeof(idx));
        for (int i=0; i<S.length(); i++)
        {
            int j = S[i] - 'A';
            ans = (ans + (i - idx[j][1])*(idx[j][1] - idx[j][0])%mod)%mod;
            idx[j][0] = idx[j][1];
            idx[j][1] = i;
        }
        for (int j = 0; j < 26; j++)
        {
            ans = (ans + (S.length() - idx[j][1])*(idx[j][1] - idx[j][0])%mod)%mod;
        }
        return ans;
    }
};