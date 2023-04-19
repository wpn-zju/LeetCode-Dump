static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class MedianFinder {
public:
	priority_queue<int> low;
	priority_queue<int, vector<int>, greater<int>> high;
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		if (low.size() == high.size()) {
			if (high.empty() || num < high.top())
				low.push(num);
			else {
				low.push(high.top());
				high.pop();
				high.push(num);
			}
		}
		else {
			if (num > low.top())
				high.push(num);
			else {
				high.push(low.top());
				low.pop();
				low.push(num);
			}
		}
	}

	double findMedian() {
		if (low.size() == high.size())
			return (double)(low.top() + high.top()) / 2;
		else
			return low.top();
	}
};