class Solution2 {
public:
    vector<int> constructArray(int n, int k) {
        int i=1, j=n;
        vector<int> ans;
        // 通过递减k， 最后一个k==1，来控制奇偶
        while(k) ans.push_back(k--%2==0 ? j-- : i++);
        while(i<=n) ans.push_back(i++);
        return ans;
    }
};
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        // [1,n]个元素最多有 n-1 个 distinct integers， 剩余元素 最小最大值依次排列即可
        // 例如[1,5]： 1,5,2,4,3 => distinct integers: 4,3,2,1
        // 先这样构造 k-1个不同的距离，剩下的元素顺序添加到末尾(正序或逆序)
        int i=1, j=n;
        vector<int> ans;
        for (int m=0; m<k; m++) ans.push_back(m%2==0 ? i++ : j--);
        for (int m=0; m<n-k; m++) 
            if (k%2==0) ans.push_back(j--);
            else ans.push_back(i++);
        return ans;
    }
};