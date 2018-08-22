class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size(), maxnum = 0, ans = 0;
        for (int i=0; i<n; i++)
        {
            maxnum = max(maxnum, arr[i]);
            if (i==maxnum) ans++;
        }
        return ans;
    }
};
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        for (int i=0; i<n; )
        {
            int maxnum = arr[i], j;
            for (j=i; j<arr[j] || j<maxnum; j++)
            {
                maxnum = max(maxnum, arr[j]);
            }
            i = j+1;
            ans++;
        }
        return ans;    
    }
};