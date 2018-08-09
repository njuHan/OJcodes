class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes = 'L' + dominoes + 'R';
        string ans = "";
        for (int i=0, j=1; j < dominoes.length(); j++)
        {
            if (dominoes[j]=='.') continue;
            int num = j-i-1;
            if (i>0) ans.push_back(dominoes[i]);
            if (dominoes[i]==dominoes[j]) ans += string(num, dominoes[i]);
            else if (dominoes[i]=='L') ans += string(num, '.');
            else ans += string(num/2, 'R') + (num%2 ? "." : "") + string(num/2, 'L');
            i = j;
        }
        return ans;
    }
};