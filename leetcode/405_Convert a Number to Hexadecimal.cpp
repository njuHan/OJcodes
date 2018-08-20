class Solution {
public:
    string toHex(int num) {
        unsigned int n = (unsigned int) num;
        if (n==0) return "0";
        static char arr[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        string ans;
        while (n)
        {
            ans.push_back(arr[n&0b1111]);
            n >>= 4;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};