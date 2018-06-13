class Solution {
public
    vectorint printMatrix(vectorvectorint  matrix) {
if (matrix.empty()) return{};
		int m = matrix.size(), n = matrix[0].size();
		vectorint ans(mn, 0);
		int up = 0, down = m - 1, left = 0, right = n - 1, k=0;
		while (true)
		{
			for (int j = left; j = right; j++) ans[k++] = matrix[up][j];
			if (++up  down) break;
			for (int i = up; i = down; i++) ans[k++] = matrix[i][right];
			if (--right  left) break;
			for (int j = right; j = left; j--) ans[k++] = matrix[down][j];
			if (--down  up) break;
			for (int i = down; i = up; i--) ans[k++] = matrix[i][left];
			if (++left  right) break;
		}
		return ans;
    }
};