static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		vector<int> result(T.size(), 0);
		vector<int> myStack;
		T.push_back(INT_MIN);
		for (int ptr = 0; ptr < T.size(); ++ptr) {
			while (myStack.size() && T[ptr] > T[myStack.back()]) {
				result[myStack.back()] = ptr - myStack.back();
				myStack.pop_back();
			}
			myStack.push_back(ptr);
		}
		return result;
	}
};