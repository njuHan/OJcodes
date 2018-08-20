class Solution {
public:
    bool isPowerOfThree(int n) {
        int maxnum = (int)(log(0x7fffffff)/log(3));
        maxnum = pow(3, maxnum);
        //cout<<maxnum;
        return n>0 && maxnum%n==0;
    }
};