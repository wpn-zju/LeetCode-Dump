class Solution {
public:
	int validSubarrays(vector<int>& nums) {
		nums.push_back(INT_MIN);
		int result = 0;
		stack<int> s;
		for (int i = 0; i < nums.size(); ++i) {
			while (!s.empty() && nums[i] < nums[s.top()]) {
				result += i - s.top();
				s.pop();
			}
			s.push(i);
		}
		return result;
	}
};