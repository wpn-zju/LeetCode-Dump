class Solution {
public:
	vector<int> cur;
	vector<int> ori;
	Solution(vector<int>& nums) {
		ori = cur = nums;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return cur = ori;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		for (int i = cur.size() - 1; i > 0; --i)
			swap(cur[i], cur[rand() % (i + 1)]);
		return cur;
	}
};