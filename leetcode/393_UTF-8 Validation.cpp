// https://en.cppreference.com/w/cpp/language/integer_literal
// int b = 0b101010; // C++14

//int bit[] = {30, 14, 6};
int bit[] = {0b11110, 0b1110, 0b110};
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int cnt = 0;
        for (int& byte : data)
        {
            if (cnt>0)
            {
                if ( (byte>>6)==2 ) cnt--;
                else return false;
            }
            else if ( (byte>>7)==0 ) continue;
            else
            {
                for (int i=0; i<3; i++)
                {
                    if ( (byte>>(i+3)) == bit[i]) cnt = 3-i;
                }
                if (cnt==0) return false;
            }
        }
        return cnt==0;
    }
};