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
#include<numeric>
using namespace std;



class MyHashMap {
public:
	/** Initialize your data structure here. */
	MyHashMap() {
		data = vector<int>(1000001, -1);
	}

	/** value will always be non-negative. */
	void put(int key, int value) {
		data[key] = value;
	}

	/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
	int get(int key) {
		return data[key];
	}

	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
	void remove(int key) {
		data[key] = -1;
	}
private:
	vector<int> data;
};