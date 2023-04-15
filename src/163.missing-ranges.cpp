static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
		vector<string> result;
		if (nums.size() == 0){
            if(lower == upper)
                result.push_back(to_string(lower));
            else
                result.push_back(to_string(lower) + "->" + to_string(upper));
            return result;
        }
        if(nums[0] == lower)
            ;
        else if(nums[0] == lower + 1)
            result.push_back(to_string(lower));
        else
            result.push_back(to_string(lower) + "->" + to_string(nums[0] - 1));
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] > (int64_t)nums[i - 1] + 1) {
				if (nums[i] == nums[i - 1] + 2)
					result.push_back(to_string(nums[i - 1] + 1));
				else
					result.push_back(to_string(nums[i - 1] + 1) + "->" + to_string(nums[i] - 1));
			}
		}
		if (nums.back() == upper)
			return result;
		else if (nums.back() == upper - 1)
			result.push_back(to_string(upper));
		else
			result.push_back(to_string(nums.back() + 1) + "->" + to_string(upper));
		return result;
	}
};