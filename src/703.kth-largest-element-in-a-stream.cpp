class KthLargest {
public:
	int k;
	priority_queue<int, vector<int>, greater<int>> myQueue;

	KthLargest(int k, vector<int>& nums) {
		this->k = k;
		for (int& i : nums)
			add(i);
	}

	int add(int val) {
		if (myQueue.size() < k)
			myQueue.push(val);
		else if (myQueue.size() >= k && val > myQueue.top()) {
			myQueue.pop();
			myQueue.push(val);
		}
        return myQueue.top();
	}
};