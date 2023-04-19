static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		priority_queue<int, vector<int>, greater<int>> myQueue;
		for (vector<int>& vec : matrix)
			for (int& i : vec)
				myQueue.push(i);
		for (int i = 0; i < k - 1; ++i)
			myQueue.pop();
		return myQueue.top();
	}
};