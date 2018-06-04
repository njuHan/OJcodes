#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<list>
#include<ctime>
using namespace std;

// how to get Leetcode tests to run approximately 10-40% faster, since they do a lot of print outs.
static auto speedhacks = []() {
	// turn off sync
	std::ios::sync_with_stdio(false);
	// untie in/out streams
	cin.tie(NULL);
	return 0;
}();

class RandomizedSet {
public:
	/** Initialize your data structure here. */
	RandomizedSet() {
		srand(time(0));
	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (val2idx.count(val)) return false;
		val2idx[val] = vec.size();
		vec.emplace_back(val);
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (val2idx.count(val) == 0) return false;
		//删除vector 末尾元素
		int back = vec.back();
		if (back != val) //将末尾元素移动到删除元素的位置
		{
			vec[val2idx[val]] = back;
			val2idx[back] = val2idx[val];
		}
		val2idx.erase(val);
		vec.pop_back();
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		//要取得[a,b)的随机整数，使用(rand() % (b-a))+ a; 
		int sz = vec.size();
		return vec[rand() % sz];
	}
private:
	unordered_map<int, int> val2idx;
	vector<int> vec;
};

/**
* Your RandomizedSet object will be instantiated and called as such:
* RandomizedSet obj = new RandomizedSet();
* bool param_1 = obj.insert(val);
* bool param_2 = obj.remove(val);
* int param_3 = obj.getRandom();
*/