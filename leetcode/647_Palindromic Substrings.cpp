
class Solution3 {
public:
    int countSubstrings(string s) {
        int n = s.length(), ans = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        for (int i=n-1; i>=0; i--) //这里顺序不能换， 先算短的 dp
            for (int j=i; j<n; j++)
            {
                dp[i][j] = s[i]==s[j] && (j-i<3 || dp[i+1][j-1]); //递推由内到外，先短后长
                ans += dp[i][j];
            }
        return ans;
    }
};

class Solution2 {
public:
    int countSubstrings(string s) {
        int ans = s.length(); //长度为1的回文个数
        for (float c = 0.5; c < s.length(); c += 0.5)
        {
            int left = c-0.5, right = c+1;
            while(left>=0 && right<s.length()&&s[left--]==s[right++]) ans++; //长度至少为2
        }
        return ans;
    }
};

class Solution {
public:
    int countSubstrings(string s) {
        ans = 0;
        for (int i=0; i<s.length(); i++)
        {
            cntPalin(s, i, i);
            cntPalin(s, i, i+1);
        }
        return ans;
    }
private:
    int ans;
    void cntPalin(string& s, int x, int y )
    {
        while(x>=0 && y<s.length() && s[x--] == s[y++]) ans++;
    }
};