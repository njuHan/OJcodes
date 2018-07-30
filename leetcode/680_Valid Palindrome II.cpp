class Solution {
public:
    bool validPalindrome(string s) {
        int x = 0, y = s.length()-1;
        while(x<y)
            if (s[x++] != s[y--]) return valid(s, x, y+1) || valid(s, x-1, y);
        return true;
    }
private:
    //[x,y] is palindrome
    bool valid(string str, int x, int y)
    {
        while(x<y)
            if (str[x++]!=str[y--]) return false;
        return true;
    }
};