class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        data = vector<bool>(1000001,0);
    }
    
    void add(int key) {
        data[key] = 1;
    }
    
    void remove(int key) {
        data[key] = 0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return data[key];
    }
private:
    vector<bool> data;
    
};