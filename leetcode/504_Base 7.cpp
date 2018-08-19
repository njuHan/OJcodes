class Solution {
public:
    string convertToBase7(int num) {
        if (num==0) return "0";
        string ans;
        bool sign = 0;
        if (num<0) {num = -num; sign = 1;}
        while (num)
        {
            ans.push_back(num%7 + '0');
            num /= 7;
        }
        if (sign) ans.push_back('-');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};