class Solution {
public:
	bool find132pattern(vector<int>& nums) {
		if (nums.size() < 3)
			return false;
		int two = INT_MIN;
		stack<int> s;
		for (int i = nums.size() - 1; i >= 0; --i) {
			if (nums[i] < two)
				return true;

			while (!s.empty() && s.top() < nums[i]) {
				two = s.top();
				s.pop();
			}

			s.push(nums[i]);
		}
		return false;
	}
};