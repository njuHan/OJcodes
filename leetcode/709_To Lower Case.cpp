class Solution {
public:
    string toLowerCase(string str) {
        for (char& ch : str)
            if ('A'<=ch && ch<='Z') ch = ch + 32;
        return str;
    }
};