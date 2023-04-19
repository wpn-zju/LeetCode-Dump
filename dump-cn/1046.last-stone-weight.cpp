static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int lastStoneWeight(vector<int>& stones) {
		priority_queue<int> myQueue;
        for(int& i : stones)
            myQueue.push(i);
		while (myQueue.size() > 1) {
			int top1 = myQueue.top();
			myQueue.pop();
			int top2 = myQueue.top();
			myQueue.pop();
			if (top1 != top2)
				myQueue.push(top1 - top2);
		}
		return myQueue.empty() ? 0 : myQueue.top();
	}
};