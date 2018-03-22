#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

class LRUCache {
public:
	LRUCache(int capacity) :cap(capacity){}

	int get(int key) 
	{
		if (cache.count(key))
		{
			auto it = cache[key].second;
			cache[key].second = update(it);
			return cache[key].first;
		}
		else
			return -1;
	}

	void put(int key, int value) 
	{
		if (cache.count(key))
		{
			cache[key].first = value;
			auto it = cache[key].second;
			cache[key].second = update(it);
		}
		else
		{
			if (cache.size() == cap)
			{
				int delkey = sortedKeys.back();
				sortedKeys.pop_back();
				cache.erase(delkey);
			}
			sortedKeys.push_front(key);
			cache.insert(pair<int, pair<int, list<int>::iterator>>(key, pair<int, list<int>::iterator>(value, sortedKeys.begin())));
		}
	}
private:
	//双向链表，根据元素的使用情况排序，每次把访问的key放在链表首
	list<int> sortedKeys;
	// 存储值 和 指向list 的下标，方便更新list
	pair<int, list<int>::iterator> valIdx;
	// cacahe, key (val,idx)
	unordered_map<int, pair<int, list<int>::iterator>> cache;
	size_t cap;

	//返回更新后的idx
	list<int>::iterator update(list<int>::iterator it)
	{
		int key = *it;
		sortedKeys.erase(it);
		sortedKeys.push_front(key);
		return sortedKeys.begin();
	}

};

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache obj = new LRUCache(capacity);
* int param_1 = obj.get(key);
* obj.put(key,value);
*/

int main()
{
	
	vector<int> vec = { 100, 4, 200, 1, 3, 2 };

	system("pause");
	return 0;
}