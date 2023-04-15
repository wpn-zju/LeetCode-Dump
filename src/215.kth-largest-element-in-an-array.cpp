class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int> myQueue;
		for (int i = 0; i < nums.size(); ++i)
			myQueue.push(nums[i]);
		for (int i = 0; i < k - 1; ++i)
			myQueue.pop();
		return myQueue.top();
	}
};