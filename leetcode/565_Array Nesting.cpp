class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        //nums 由 若干个不相交的环组成，依次遍历
        int n = nums.size(), ans = 0;
        vector<bool> vis(n, 0);
        for (int i=0; i<n; i++)
        {
            if (vis[i]) continue;
            int cnt = 0;
            for(int j = i; !vis[j]; j = nums[j])
            {
                vis[j] = 1;
                //cout<<j<<",";
                cnt++;
            }
            ans = max(ans, cnt);
            //cout<<endl;
        }
        return ans;
    }
};