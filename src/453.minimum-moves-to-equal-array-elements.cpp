static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int minMoves(vector<int>& nums) {
		int min = nums[0];
		int result = 0;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] < min) {
				result += i * (min - nums[i]);
				min = nums[i];
			}
			else
				result += nums[i] - min;
		}
		return result;
	}
};