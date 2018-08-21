class Solution {
public:
    int countArrangement(int N) {
        vis = vector<bool>(N+1, 0);
        ans = 0;
        search(1,N);
        return ans;
    }
private:
    vector<bool> vis;
    int ans;
    void search(int cur, int n)
    {
        if (cur>n) {ans++; return;}
        for (int i=1; i<=n; i++)
        {
            if (vis[i]==0 && (i%cur==0 || cur%i==0))
            {
                vis[i]=1;
                search(cur+1, n);
                vis[i]=0;
            }
        }
    }
};