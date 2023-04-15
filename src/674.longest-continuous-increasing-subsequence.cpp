static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
		int result = 1;
		int cur = 1;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] > nums[i - 1]) {
				++cur;
				result = max(result, cur);
			}
			else
				cur = 1;
		}
		return result;
	}
};