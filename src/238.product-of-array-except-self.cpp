class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> result(nums.size(), 1);
		int left = 1;
		int right = 1;
		for (int i = 0; i < nums.size(); ++i) {
			result[i] *= left;
			result[nums.size() - i - 1] *= right;
			left *= nums[i];
			right *= nums[nums.size() - i - 1];
		}
		return result;
	}
};