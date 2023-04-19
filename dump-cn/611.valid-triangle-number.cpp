class Solution {
public:
	int triangleNumber(vector<int>& nums) {
        nums.push_back(INT_MIN);
        nums.push_back(INT_MAX);
		int result = 0;
		sort(nums.begin(), nums.end());
		for (int i = 1; i < nums.size() - 1; ++i) {
			for (int j = i + 1; j < nums.size() - 1; ++j) {
				int start = j + 1, end = nums.size() - 1;
				int tmp = abs(nums[i] - nums[j]);
				while (start < end) {
					int mid = start + (end - start >> 1);
					if (nums[mid] <= tmp)
						start = mid + 1;
					else
						end = mid;
				}
				int L = start;
				start = j + 1, end = nums.size() - 1;
				tmp = nums[i] + nums[j];
				while (start < end) {
					int mid = start + (end - start >> 1);
					if (nums[mid] < tmp)
						start = mid + 1;
					else
						end = mid;
				}
				if (start - L > 0)
					result += start - L;
			}
		}
		return result;
	}
};