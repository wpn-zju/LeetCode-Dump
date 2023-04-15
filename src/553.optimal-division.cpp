class Solution {
public:
	string optimalDivision(vector<int>& nums) {
		if (nums.size() == 1)
			return to_string(nums[0]);
		else if (nums.size() == 2)
			return to_string(nums[0]) + '/' + to_string(nums[1]);
		string result = move(to_string(nums[0]));
		result += "/(";
		for (int i = 1; i < nums.size(); ++i)
			result += to_string(nums[i]) + '/';
		result.pop_back();
		result += ')';
		return result;
	}
};