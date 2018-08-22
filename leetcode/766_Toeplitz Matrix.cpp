class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 1;
        int m = matrix.size(), n = matrix[0].size();
        unordered_map<int, int> dig;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                int k = i-j+n;
                if (dig.count(k))
                {
                    if (dig[k]!=matrix[i][j]) return 0;
                }
                else
                    dig[k] = matrix[i][j];
            }
        return 1;
    }
};