#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
using namespace std;

class NumArray {
public:
	NumArray(vector<int> nums) {
		a = nums;
		n = nums.size();
		if (n > 0)
		{
			sum = vector<int>(n << 2, 0);
			add = vector<int>(n << 2, 0);
			build(0, n-1, 1);
		}
	}

	void update(int i, int val) {
		if (n < 1) return;
		int c = val - a[i];
		update(i, c, 0, n-1, 1);
	}

	int sumRange(int i, int j) {
		if (n < 1) return 0;
		return query(i, j, 0, n-1, 1);
	}
private:
	int n;
	vector<int> a;
	vector<int> sum;
	vector<int> add;

	//build tree
	void pushUp(int rt)
	{
		sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	}
	void build(int l, int r, int rt) //l,r表示当前节点区间，rt表示当前节点编号  
	{
		if (l == r)
		{
			sum[rt] = a[l];
			return;
		}
		int m = l + ((r - l) >> 1); //中间点
		build(l, m, rt << 1);
		build(m + 1, r, rt << 1 | 1); //注意这里m+1
		pushUp(rt);
	}

	//点修改
	//a[x] += c;
	void update(int x, int c, int l, int r, int rt) //l,r表示当前节点区间，rt表示当前节点编号  
	{
		if (l == r)
		{
			sum[rt] += c;
			a[l] += c;
			return;
		}
		int m = l + ((r - l) >> 1);
		if (x <= m) update(x, c, l, m, rt << 1);//左子树
		else update(x, c, m + 1, r, rt << 1 | 1); //右子树
		pushUp(rt);
	}


	//下推标记的函数
	//下推修改子结点的sum值
	void pushDown(int rt, int ln, int rn) //ln,rn为左子树，右子树的数字数量。   
	{
		if (add[rt])
		{
			//下推标记
			add[rt << 1] += add[rt];
			add[rt << 1 | 1] += add[rt];
			//修改子节点的Sum使之与对应的Add相对应 
			sum[rt << 1] += add[rt] * ln;
			sum[rt << 1 | 1] += add[rt] * rn;
			//清除本节点标记   
			add[rt] = 0;
		}
	}

	//区间修改
	//a[x, y] += c;
	void update(int x, int y, int c, int l, int r, int rt)
	{
		if (x <= l && r <= y) //如果本区间完全在操作区间[x, y]以内,才更新sum,add
		{
			sum[rt] += c*(r - l + 1); //更新数字和，向上保持正确  
			add[rt] += c; //增加Add标记，表示本区间的Sum正确，子区间的Sum仍需要根据Add的值来调整  
			return; //return, 暂时不下推
		}
		int m = l + ((r - l) >> 1);
		pushDown(rt, m - l + 1, r - m); //下推标记  
										//这里判断左右子树跟[L,R]有无交集，有交集才递归 
		if (x <= m) update(x, y, c, l, m, rt << 1);
		if (y >= m + 1) update(x, y, c, m + 1, r, rt << 1 | 1);
		pushUp(rt); //更新本节点信息   
	}


	int query(int x, int y, int l, int r, int rt) //x,y表示操作区间，l,r表示当前节点区间，rt表示当前节点编号 
	{
		if (x <= l && r <= y)
		{
			return sum[rt]; //在区间内，直接返回  
		}
		int m = l + ((r - l) >> 1);
		//下推标记，否则Sum可能不正确  
		pushDown(rt, m - l + 1, r - m);

		int ans = 0;
		if (x <= m) ans += query(x, y, l, m, rt << 1);
		if (y >= m + 1) ans += query(x, y, m + 1, r, rt << 1 | 1);
		return ans;
	}

};

int main()
{
	NumArray num(vector<int>{-1});
	int ans;
	ans = num.sumRange(0, 0);
	cout << ans;
	num.update(0, 1);
	ans = num.sumRange(0, 0);
	cout << ans;
	system("pause");
	return 0;
}