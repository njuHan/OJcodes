class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(), ans = 0;
        vector<int> bits(n, 0);
        for (int i=0; i<n; i++)
            for (char ch : words[i])
                bits[i] |= (1<<(ch-'a'));
        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++)
                if ((bits[i]&bits[j])==0) ans = max(ans, (int)words[i].length() * (int)words[j].length());
        return ans;
    }
};