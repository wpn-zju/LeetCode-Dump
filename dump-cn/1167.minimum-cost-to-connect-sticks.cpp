class Solution {
public:
	int connectSticks(vector<int>& sticks) {
		priority_queue<int, vector<int>, greater<int>> myQueue;
		for (int& i : sticks)
			myQueue.push(i);
		int result = 0;
		while (myQueue.size() > 1) {
			int i1 = myQueue.top();
			myQueue.pop();
			int i2 = myQueue.top();
			myQueue.pop();
			myQueue.push(i1 + i2);
			result += i1 + i2;
		}
		return result;
	}
};