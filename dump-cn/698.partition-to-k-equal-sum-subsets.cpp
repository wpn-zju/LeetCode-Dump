class Solution {
public:
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		int sum = 0;
		for (int& i : nums)
			sum += i;
		if (sum % k)
			return false;
		sort(nums.begin(), nums.end(), greater<int>());

		int ave = sum / k;
		bool result = false;
		vector<int> sub(k, 0);
		int index = 0;
		dfsCanPart(nums, sub, index, result, ave);

		return result;
	}

	void dfsCanPart(vector<int>& nums, vector<int>& sub, int& index, bool& result, int& ave) {
		if (result)
			return;
		if (index == nums.size()) {
			result = true;
			return;
		}
		for (int i = 0; i < sub.size(); ++i) {
			if (sub[i] + nums[index] <= ave) {
				sub[i] += nums[index];
				++index;
				dfsCanPart(nums, sub, index, result, ave);
				--index;
				sub[i] -= nums[index];
			}
		}
	}
};