class Solution {
public:
	bool leqVec(vector<int>& a, vector<int>& b) {
		return a[0] < b[0] && a[1] < b[1];
	}

	bool geqVec(vector<int>& a, vector<int>& b) {
		return a[0] > b[0] && a[1] > b[1];
	}

	int binarySearch(vector<vector<int>>& nums, int length, vector<int>& target) {
		int start = 0;
		int end = length - 1;
		while (start < end) {
			int mid = (start + end) / 2;
			if (leqVec(nums[mid], target))
				start = mid + 1;
			else
				end = mid;
		}
		return start;
	}

	int maxEnvelopes(vector<vector<int>>& nums) {
		if (nums.empty())
			return 0;
		sort(nums.begin(), nums.end(), [](vector<int>& a, vector<int>& b) {
			return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
		});
		int length = 1;
		for (int i = 1; i < nums.size(); ++i) {
			if (geqVec(nums[i], nums[length - 1]))
				nums[length++] = nums[i];
			else
				nums[binarySearch(nums, length, nums[i])] = nums[i];
		}
		return length;
	}
};