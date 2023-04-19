class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		unordered_map<int, int> match;
		stack<int> s1;
		stack<int> s2;
		for (int n = 0; n < 2; ++n) {
			for (int i = 0; i < nums.size(); ++i) {
				while (!s1.empty() && s1.top() < nums[i]) {
					if (!match.count(s2.top()))
						match[s2.top()] = nums[i];
					s1.pop();
					s2.pop();
				}
				s1.push(nums[i]);
				s2.push(i);
			}
		}
		while (!s2.empty()) {
			if (!match.count(s2.top()))
				match[s2.top()] = -1;
			s1.pop();
			s2.pop();
		}
		for (int i = 0; i < nums.size(); ++i) {
			nums[i] = match[i];
		}
		return nums;
	}
};