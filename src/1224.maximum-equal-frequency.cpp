static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int maxEqualFreq(vector<int>& nums) {
		int result = 0;
		vector<int> freq(100000, 0);
		vector<int> count(100000, 0);
		for (int i = 0; i < nums.size(); ++i) {
			if (count[nums[i] - 1])
				--freq[count[nums[i] - 1]];
			++freq[++count[nums[i] - 1]];
            if (freq[count[nums[i] - 1]] * count[nums[i] - 1] == i + 1 && i < nums.size() - 1)
				result = max(result, i + 2);
			else if (freq[count[nums[i] - 1]] * count[nums[i] - 1] == i 
				|| freq[count[nums[i] - 1]] * count[nums[i] - 1] == i - count[nums[i] - 1] 
				|| freq[count[nums[i] - 1] - 1] * (count[nums[i] - 1] - 1) == i - count[nums[i] - 1] + 1)
				result = max(result, i + 1);
		}
		return result;
	}
};