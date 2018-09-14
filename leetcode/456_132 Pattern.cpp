class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n<3) return 0;
        stack<int> sk;
        int two = INT_MIN; // two is 2 of 132;
        //finding 32, record 2, if (num < 2) return true;
        // stack num from bottom to top, is from max to min
        for (int i=n-1; i>=0; i--)
        {
            if (nums[i]<two) return 1;
            while(!sk.empty() && sk.top() < nums[i]) {two = sk.top(); sk.pop();}
            sk.push(nums[i]);
        }
        return 0;
    }
    
};