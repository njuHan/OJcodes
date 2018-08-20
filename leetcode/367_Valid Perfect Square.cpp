/*
平方序列：1,4,9,16,..
间隔：3,5,7,...
间隔为等差数列，使用这个特性可以得到从 1 开始的平方序列。
*/

class Solution2 {
public:
    bool isPerfectSquare(int num) {
        int sub = 1;
        while (num>0)
        {
            num -= sub;
            sub += 2;
        }
        return num == 0;
    }
};

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long  i2 = 1, i = 1;
        while(i2<num)
            i2 += 2*(i++) + 1;
        return i2 == num;
    }
};