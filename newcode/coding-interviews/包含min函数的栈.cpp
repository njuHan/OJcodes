class Solution {
public:
	void push(int value) {
		sk.push(value);
		minsk.empty() ? minsk.push(value) : minsk.push(std::min(minsk.top(), value));
	}
	void pop() {
		sk.pop();
		minsk.pop();
	}
	int top() {
		return sk.top();
	}
	int min() {
		return minsk.top();
	}
private:
	stack<int> sk, minsk;
};