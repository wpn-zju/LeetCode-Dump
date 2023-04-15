static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.size() == 0)
            return result;
		int last = 0;
		for (int i = 1; i < nums.size(); ++i)
			if ((int64_t)nums[i] - nums[last] != i - last) {
				if (i - 1 == last)
					result.push_back(to_string(nums[last]));
				else
					result.push_back(to_string(nums[last]) + "->" + to_string(nums[i - 1]));
				last = i;
			}
        if(nums.size() - 1 == last)
            result.push_back(to_string(nums[last]));
        else
            result.push_back(to_string(nums[last]) + "->" + to_string(nums.back()));
        return result;
	}
};