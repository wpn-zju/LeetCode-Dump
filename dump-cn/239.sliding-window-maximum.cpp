static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int m = nums.size();
		vector<int> result;
		if (k == 0 || k > m)
			return result;
		int max = INT_MIN;
		for (int i = 0; i < k; ++i)
			max = std::max(max, nums[i]);
		result.push_back(max);
		for (int ptr = k; ptr < m; ptr++) {
			if (result[ptr - k] <= nums[ptr])
				result.push_back(nums[ptr]);
			else if (result[ptr - k] != nums[ptr - k])
				result.push_back(result[ptr - k]);
			else
			{
				max = INT_MIN;
				for (int i = ptr - k + 1; i <= ptr; ++i)
					max = std::max(max, nums[i]);
				result.push_back(max);
			}
		}
		return result;
	}
};