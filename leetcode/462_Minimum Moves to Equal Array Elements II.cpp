class Solution2 {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int x = 0, y = nums.size()-1, ans = 0;
        while(x<y) ans += nums[y--] - nums[x++];
        return ans;    
    }
};

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int x = 0, y = nums.size();
        int k = x + (y-x)/2, ans = 0;
        while(true)
        {
            int mid = split(nums, x, y);
            if (mid == k) break;
            else if (mid<k) x = mid +1;
            else y = mid;
        }
        for (int num : nums)
            ans += abs(num - nums[k]);
        return ans;
    }
    int split(vector<int>& nums, int x, int y)
    {
        int val = nums[x], pivot = x;
        for (int i=x; i<y; i++) if (nums[i] < val) swap(nums[++pivot], nums[i]);
        swap(nums[x], nums[pivot]);
        return pivot;
    }
};