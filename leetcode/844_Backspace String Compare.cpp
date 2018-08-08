class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int p = S.length()-1, q = T.length()-1, cnt1 = 0, cnt2 = 0;
        for (; ; p--, q--)
        {
            for (; p>=0 && (cnt1>0 || S[p]=='#'); p--) cnt1 += (S[p]=='#' ? 1 : -1);
            for (; q>=0 && (cnt2>0 || T[q]=='#'); q--) cnt2 += (T[q]=='#' ? 1 : -1);
            if (p<0 || q<0 || S[p]!=T[q]) return p==-1 && q==-1;
        }
    }
};