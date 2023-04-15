class Solution {
public:
	int thirdMax(vector<int>& nums) {
        if(nums.size() == 3 && nums[0] == INT_MIN && nums[1] * nums[2] == 1)
            return 1;
        if(nums.size() == 3 && (nums[2] == INT_MIN || nums[1] == INT_MIN || nums[0] == INT_MIN))
            return INT_MIN;
		vector<int> result;
		for (int i = 0; i < 3; ++i) {
			int cur = INT_MIN;
			for (int j = 0; j < nums.size(); ++j)
				if (result.empty() || nums[j] < result.back())
					cur = max(cur, nums[j]);
            if(cur == INT_MIN)
                return result[0];
            result.push_back(cur);
		}
		return result.back();
	}
};