static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int largestSumAfterKNegations(vector<int>& A, int K) {
		priority_queue<int, vector<int>, greater<int>> myQueue;
		for (int& i : A)
			myQueue.push(i);
		while (K--) {
			int tmp = myQueue.top();
			myQueue.pop();
			myQueue.push(-tmp);
		}
		int result = 0;
		while (!myQueue.empty()) {
			result += myQueue.top();
			myQueue.pop();
		}
		return result;
	}
};